#!/usr/bin/python

import re

class Callback:
    def __init__(self):
        self.r_file = open("CXeleTraderApi.hpp")
        self.o_file = open('Callback.hh', 'wb')
        self.func_index = 2

    def callbackHandle(self, line):
        words = re.split('\s|,|\(|\)|{|}|;|\*', line)
        words = filter(None, words)

        # print words
        func_name = words[self.func_index]
        callback_name = func_name[0].lower() + func_name[1:]
        # print func_name
        self.o_file.write("virtual void %s(\n" % callback_name)
        args = []
        for index in xrange(3, len(words), 2):
            if index+1 == len(words)-1:
                last_flag = ''
            else:
                last_flag = ',\n'

            arg = words[index+1]
            var = words[index]
            if arg[0] == 'p':
                var = 'const std::string&'
                arg = 'the' + arg[1:];
            args.append(arg)
            self.o_file.write('\t%s %s%s' % (var, arg, last_flag))
        self.o_file.write(') {\n')
        self.o_file.write('\tSOIL_FUNC_TRACE;\n\n')
        for arg in args:
            self.o_file.write('\tSOIL_DEBUG_PRINT(%s);\n' % arg)
        self.o_file.write('}\n\n')


    def Main(self):
        callback_pattern = re.compile(r'''(OnRsp|OnRtn|OnErrRtn)''')
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
    Callback().Main()

