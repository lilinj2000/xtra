#!/usr/bin/python

import re

callback_pattern = re.compile(r'''(OnRsp|OnQuery|OnOrder|OnCxl|OnPost|OnMarket|OnSymbol)''')
comment_pattern = re.compile(r'''///''')
ees_pattern = re.compile(r'''EES_''')

file = open("EesTraderApi.h")

output_file = open('Callback.hh', 'wb')

func_index = 2
index = 3

for line in file:
    # print line
    if comment_pattern.search(line):
        continue;

    result = callback_pattern.search(line)
    if result:
        # print line
        words = re.split('\s|,|\(|\)|{|}|;|\*', line)
        words = filter(None, words)
        words = filter(lambda k: 'const' != k, words)
        # print words

        func_name = words[func_index]
        callback_name = func_name[0].lower() + func_name[1:]
        # print callback_name
        output_file.write("virtual void %s(\n" % callback_name)
        args = []
        for index in xrange(3, len(words), 2):
            if index+1 == len(words)-1:
                last_flag = ''
            else:
                last_flag = ',\n'

            arg = ''
            var = ''
            if words[index+1][0] == 'p':
                arg = 'the' + words[index+1][1:]
                var = 'const std::string&'
            elif ees_pattern.search(words[index]) and words[index+1][0] == 'n':
                arg = words[index+1]
                var = 'int';
            elif words[index] == 'EES_MarketSessionId':
                arg = words[index+1]
                var = 'unsigned char'
            else:
                arg = words[index+1]
                var = words[index]

            args.append(arg)
            output_file.write('\t%s %s%s' % (var, arg, last_flag))
        output_file.write(') {\n')

        output_file.write('\tSOIL_FUNC_TRACE;\n\n')
        for arg in args:
            output_file.write('\tSOIL_DEBUG_PRINT(%s);\n' % arg)
        output_file.write('}\n\n')
        # print args
                

        # print '%s' % result.groups()


    


