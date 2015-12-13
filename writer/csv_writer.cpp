/*
 Created by Xavier on 2015/12/5.
*/

#include <vector>

#include "csv_writer.h"
#include "../csv_parser/result_iterator.h"

using namespace std;
using namespace zeus;

CSVWriter::CSVWriter() { };

/*
 * Constructor
 * @param fileName, the file name want to write
 * @param mode, append or just write
 */
CSVWriter::CSVWriter(const std::string &fileName, std::_Ios_Openmode mode) {
    mOutFile.open(fileName, mode);
}

CSVWriter::~CSVWriter() {
    if(this->mOutFile.is_open()){
        this->mOutFile.close();
    }
}

/*
 * Wirte content to file
 * @param content, the content want to write,use csv style
 * @return bool, return the mark indicate if it is successful
 */
bool CSVWriter::write(const std::vector<std::string> &content) {
    if(!(this->mOutFile.is_open()))
        return false;
    (this->mOutFile) << "\n";
    for(const string& word : content){
        (this->mOutFile) << word+",";
    }
    return true;
}

/*
 * Wirte content to file
 * @param itr, it is a result_iterator
 * @return bool, return the mark indicate if it is successful
 */
bool CSVWriter::write(result_iterator itr) {
    this->write(*itr);
}

/*
 * Wirte content to file
 * @param content, it is a csv string
 * @return bool, return the mark indicate if it is successful
 */
bool CSVWriter::write(const std::string &content) {
    if(!(this->mOutFile.is_open()))
        return false;
    (this->mOutFile) << content;
    return true;
}
