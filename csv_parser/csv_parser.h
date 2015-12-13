/*
  Created by Xavier on 2015/12/4.
*/

#ifndef ZEUS_CSV_PARSER_H
#define ZEUS_CSV_PARSER_H

#include <fstream>
#include <vector>
#include <string>

#include "../csv_parser/result_iterator.h"
#include "result_iterator.h"

/*
 * This is a parser for csv file, use result_iterator
 * to read the content
 */

namespace zeus{

    class CSVParser {
        std::string mFileName;
        std::ifstream mInFile;

    public:
        CSVParser();
        CSVParser(const std::string& fileName);
        ~CSVParser();

        result_iterator begin();
        result_iterator end();
        std::vector<std::string> find(std::string pattern,size_t pos);
        size_t count(std::string pattern, size_t pos);
        bool exist(std::vector<std::string>& content);
    };
}


#endif //ZEUS_CSV_PARSER_H
