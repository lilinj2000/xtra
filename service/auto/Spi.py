#!/usr/bin/python

import re

class Spi:
    def __init__(self):
        self.r_file = open("CXeleTraderApi.hpp")
        self.hh_file = open('Spi.hh', 'wb')
        self.cc_file = open('Spi.cc', 'wb')
        self.func_index = 2

    def callbackHandle(self, line):
        words = re.split('\s|,|\(|\)|{|}|;|\*', line)
        words = filter(None, words)

        # print words
        func_name = words[self.func_index]
        callback_name = func_name[0].lower() + func_name[1:]
        # print func_name
        if len(words)==3:
            self.hh_file.write("virtual void %s();\n\n" % func_name)
            self.cc_file.write("void TraderSpiImpl::%s() {\n" % func_name)
            self.cc_file.write("\tSOIL_FUNC_TRACE;\n}\n\n")
            return

        self.hh_file.write("virtual void %s(\n" % func_name)
        self.cc_file.write("void TraderSpiImpl::%s(\n" % func_name)
        args = []
        for index in xrange(3, len(words), 2):
            if index+1 == len(words)-1:
                last_flag = ''
            else:
                last_flag = ',\n'

            arg = words[index+1]
            var = words[index]
            if arg[0] == 'p':
                var = var + '*'
            args.append(arg)
            self.hh_file.write('\t%s %s%s' % (var, arg, last_flag))
            self.cc_file.write('\t%s %s%s' % (var, arg, last_flag))
        self.hh_file.write(');\n\n')
        self.cc_file.write(') {\n')

        self.cc_file.write('\tSOIL_FUNC_TRACE;\n\n')
        is_callback = False

        on_callback_pattern = re.compile(r'''(OnRsp|OnRtn|OnErrRtn)''')
        if on_callback_pattern.search(line):
            is_callback = True
            self.cc_file.write('\tif (callback()) {\n')
            self.cc_file.write('\t\tcallback()->%s(\n' % callback_name)

        first_arg = True
        for arg in args:
            arg_pointer = False
            if arg[0] == 'p':
                arg_pointer = True
                # arg = arg.replace('*', '')

            if is_callback:
                if not first_arg:
                    self.cc_file.write(',\n')

                if arg_pointer:
                    self.cc_file.write('\t\t\t%s ? fmt::format("{}", *%s) : ""' % (arg, arg))
                else:
                    self.cc_file.write('\t\t\t%s' % arg)
            elif arg_pointer:
                self.cc_file.write('\tSOIL_DEBUG_IF_PRINT(%s);\n' % arg)
            else:
                self.cc_file.write('\tSOIL_DEBUG_PRINT(%s);\n' % arg)
            if first_arg:
                first_arg = False

        if is_callback:
            self.cc_file.write(');\n')
            self.cc_file.write('\t}\n')
        self.cc_file.write('}\n\n')


    def Main(self):
        callback_pattern = re.compile(r'''On''')
        rightbrace_pattern = re.compile(r'''\)''')

        whole_line = ''
        for line in self.r_file:
            # print line
            whole_line = whole_line + line

            result = callback_pattern.search(whole_line)
            if result:
                if not rightbrace_pattern.search(whole_line):
                    continue
                self.callbackHandle(whole_line)

            whole_line = ''


if __name__ == "__main__":
    Spi().Main()
