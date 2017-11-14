#!/usr/bin/python

import re

callback_pattern = re.compile(r'''On''')
setlogger_pattern = re.compile(r'''SetLoggerSwitch''')
on_callback_pattern = re.compile(r'''(OnRsp|OnQuery|OnOrder|OnCxl|OnPost|OnMarket|OnSymbol)''')
comment_pattern = re.compile(r'''///''')

# file = open("ThostFtdcMdApi.h")
file = open("EesTraderApi.h")

hh_file = open('Spi.hh', 'wb')
cc_file = open('Spi.cc', 'wb')

func_index = 2
index = 3

for line in file:
    # print line
    if comment_pattern.search(line):
        continue

    result = callback_pattern.search(line) and (not setlogger_pattern.search(line))
    if result:
        # print line
        words = re.split('\s|,|\(|\)|{|}|;|\*', line)
        words = filter(None, words)
        words = filter(lambda k: 'const' != k, words)
        print words
        # continue

        func_name = words[func_index]
        callback_name = func_name[0].lower() + func_name[1:]
        # print func_name
        if len(words)==3:
            hh_file.write("virtual void %s();\n\n" % func_name)
            cc_file.write("void MDSpiImpl::%s() {\n" % func_name)
            cc_file.write("\tSOIL_FUNC_TRACE;\n}\n\n")
            continue

        hh_file.write("virtual void %s(\n" % func_name)
        cc_file.write("void MDSpiImpl::%s(\n" % func_name)
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
            if var == 'char*':
                var = 'const char*'
            args.append(arg)
            hh_file.write('\t%s %s%s' % (var, arg, last_flag))
            cc_file.write('\t%s %s%s' % (var, arg, last_flag))
        hh_file.write(');\n\n')
        cc_file.write(') {\n')

        cc_file.write('\tSOIL_FUNC_TRACE;\n\n')
        is_callback = False

        if on_callback_pattern.search(line):
            is_callback = True
            cc_file.write('\tif (callback()) {\n')
            cc_file.write('\t\tcallback()->%s(\n' % callback_name)

        first_arg = True
        for arg in args:
            arg_pointer = False
            if arg[0] == 'p':
                arg_pointer = True
                # arg = arg.replace('*', '')

            if is_callback:
                if not first_arg:
                    cc_file.write(',\n')

                if arg_pointer:
                    cc_file.write('\t\t\t%s ? fmt::format("{}", *%s) : ""' % (arg, arg))
                else:
                    cc_file.write('\t\t\t%s' % arg)
            elif arg_pointer:
                cc_file.write('\tSOIL_DEBUG_IF_PRINT(%s);\n' % arg)
            else:
                cc_file.write('\tSOIL_DEBUG_PRINT(%s);\n' % arg)
            if first_arg:
                first_arg = False

        if is_callback:
            cc_file.write(');\n')
            cc_file.write('\t}\n')
        cc_file.write('}\n\n')



    


