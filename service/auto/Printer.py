#!/usr/bin/python

import re

class Printer:
    def __init__(self):
        self.r_file = open("CXeleFtdcUserApiStruct.h")
        self.o_file = open('CXeleFtdcUserApiStructPrint.hh', 'wb')
        self.struct_status = False
        self.stru_name = ''
        self.obj_name = ''

    def fileHead(self):
        self.o_file.write('// Copyright (c) 2010\n')
        self.o_file.write('// All rights reserved.\n\n')
        self.o_file.write('#ifndef CXELE_FTDC_USERAPI_STRUCT_PRINT_HH\n')
        self.o_file.write('#define CXELE_FTDC_USERAPI_STRUCT_PRINT_HH\n\n')

        self.o_file.write('#include <ostream>\n')
        self.o_file.write('#include "CXeleFtdcUserApiStruct.h"\n')
        self.o_file.write('#include "soil/json.hh"\n\n')

        self.o_file.write('using rapidjson::StringBuffer;\n')
        self.o_file.write('using rapidjson::PrettyWriter;\n')
        self.o_file.write('using soil::json::write_value;\n\n')

    def fileTail(self):
        self.o_file.write('#endif\n')
    
    def structHandle(self):
        self.obj_name = 'a' + self.stru_name.replace('CXeleFtdc', '')
        self.o_file.write('inline std::ostream& operator<<(\n')
        self.o_file.write('    std::ostream& os,\n')
        self.o_file.write('    %s const& %s)' % (self.stru_name, self.obj_name))

    def leftBraceHandle(self):
        self.o_file.write(' {  // NOLINT\n')
        self.o_file.write('    StringBuffer sb;\n')
        self.o_file.write('    PrettyWriter<StringBuffer> writer(sb);\n\n')
        self.o_file.write('    writer.StartObject();\n')
        self.o_file.write('    writer.Key(\"%s\");\n' % self.stru_name)
        self.o_file.write('        writer.StartObject();\n')

    def rightBraceHandle(self):
        self.o_file.write('        writer.EndObject();\n')
        self.o_file.write('    writer.EndObject();\n\n')
        self.o_file.write('    os <<sb.GetString();\n\n')
        self.o_file.write('    return os;\n')
        self.o_file.write('}\n\n')

    def fieldHandle(self, m_name):
        self.o_file.write('        writer.Key(\"%s\");\n' % m_name)
        self.o_file.write('        write_value(\n')
        self.o_file.write('            &writer,\n')
        self.o_file.write('            %s.%s);\n' % (self.obj_name, m_name))

    def Main(self):
        self.fileHead()

        struct_pattern = re.compile(r'''struct (.*)''')
        left_brace_pattern = re.compile(r'''\{''')
        right_brace_pattern = re.compile(r'''\};''')
        comment_pattern = re.compile(r'''///''')
        field_pattern = re.compile(r'''\s+(\w+)\s+(\w+);''')

        for line in self.r_file:
            # print line
            result = struct_pattern.search(line)
            if result:
                # print '%s' % result.groups()
                self.stru_name = result.group(1)
                self.structHandle()
                continue

            if left_brace_pattern.search(line):
                # print 'left brace: %s' % line
                self.struct_status = True
                self.leftBraceHandle()
                continue

            if right_brace_pattern.search(line):
                # print 'right brace: %s' % line
                self.struct_status = False
                self.rightBraceHandle()
                continue

            if comment_pattern.search(line):
                # print 'comment: %s' % line
                continue

            result = field_pattern.search(line)
            if result:
                # print 'field: %s\t%s' % (result.group(1), result.group(2))
                if self.struct_status:
                    self.fieldHandle(result.group(2))
                continue

        self.fileTail()

if __name__ == "__main__":
    Printer().Main()
