/*
 Created by Xavier on 2015/12/4.
*/

#include <string>

#include "csv_parser.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;

CSVParser::CSVParser() { };

CSVParser::CSVParser(const std::string &fileName):mFileName(fileName){
    mInFile.open(fileName);
}

result_iterator CSVParser::begin() {
    if(this->mInFile.is_open()){
        mInFile.close();
    }
    this->mInFile.open(this->mFileName);
    return result_iterator(this->mInFile);
}

result_iterator CSVParser::end(){
    return result_iterator();
}

vector<string> CSVParser::find(string pattern, size_t pos) {
    vector<string> result;
    result_iterator itr = this->begin();
    for(; *(itr.getPtr()); ++itr){
        result = (*itr);
        if(result.size() <= pos){
            return vector<string>();
        }
        else if(result[pos] == pattern){
            return *itr;
        }
    }
    return vector<string>();
}

size_t CSVParser::count(std::string pattern, size_t pos) {
    size_t c = 0;
    result_iterator itr = this->begin();
    for(; *(itr.getPtr()); ++itr){
        vector<string> result = (*itr);
        if(result.size() >= pos){
            return 0;
        }
        if(result[pos] == pattern){
            ++c;
        }
    }
    return c;
}


bool CSVParser::exist(std::vector<std::string> &content) {
    result_iterator itr = this->begin();
    for(; *(itr.getPtr()); ++itr){
        vector<string> result = *itr;
        if(result.size() != content.size())
            return false;
        if(result == content)
            return true;
    }
    return false;
}

CSVParser::~CSVParser() {
    if(mInFile.is_open()){
        mInFile.close();
    }
}
