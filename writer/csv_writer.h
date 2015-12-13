/*
 Created by Xavier on 2015/12/5.
*/

#ifndef ZEUS_CSV_WRITER_H
#define ZEUS_CSV_WRITER_H

#include <fstream>
#include <vector>
#include <iostream>

#include "../csv_parser/result_iterator.h"

namespace zeus{

    class CSVWriter {
        std::ofstream mOutFile;
    public:
        CSVWriter();

        CSVWriter(const std::string& fileName, std::_Ios_Openmode mod);

        ~CSVWriter();

        bool write(const std::vector<std::string>& content);

        bool write(const std::string& content);

        bool write(result_iterator itr);
    };
}



#endif //ZEUS_CSV_WRITER_H
