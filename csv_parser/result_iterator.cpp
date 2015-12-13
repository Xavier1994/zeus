/*
 Created by Xavier on 2015/12/4.
*/

#include <iostream>
#include <fstream>

#include "result_iterator.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;

/*
 * Constructor
 */
result_iterator::result_iterator() {
    this->mInFilePtr = NULL;
}

/*
result_iterator::result_iterator(const std::string &fileName) {
    this->mInFilePtr = shared_ptr<ifstream>(new ifstream(fileName));
    if(!(this->mInFilePtr)->is_open()){
        this->mInFilePtr = NULL;
    }
}
 */


/*
 * Constructor
 * @param ifstream& inFile
 */
result_iterator::result_iterator(std::ifstream &inFile) {
    this->mInFilePtr = shared_ptr<ifstream>(&inFile);
    string buffer;
    getline(*(this->mInFilePtr),buffer,'\n');
    this->mRes = StringHelper::StringSplit(buffer, ' ');
}

/*
 * Deconstructor, if the file is open, just close it;
 */
result_iterator::~result_iterator() {
    if((this->mInFilePtr)->is_open()){
        (this->mInFilePtr)->close();
    }
}

const vector<string>& result_iterator::operator*(){
    return this->mRes;
}

vector<string>* result_iterator::operator->(){
    return &(this->mRes);
}

/*
 * Use this operation to read the next line
 */
result_iterator& result_iterator::operator++() {
    string buffer;
    getline(*(this->mInFilePtr),buffer,'\n');
    this->mRes = StringHelper::StringSplit(buffer, ',');
    return (*this);
}

result_iterator result_iterator::operator++(int) {
    result_iterator tmp(*this);
    string buffer;
    getline(*(this->mInFilePtr),buffer,'\n');
    this->mRes = StringHelper::StringSplit(buffer, ',');
    return tmp;
}

result_iterator::result_iterator(const result_iterator &rhs) {
    this->mInFilePtr = rhs.mInFilePtr;
}

result_iterator &result_iterator::operator=(const result_iterator &rhs) {
    if(this->mInFilePtr == rhs.mInFilePtr)
        return *this;
    this->mInFilePtr = rhs.mInFilePtr;
    return *this;
}


std::shared_ptr<std::ifstream> result_iterator::getPtr() {
    return this->mInFilePtr;
}

/*
bool result_iterator::operator==(const result_iterator &rhs) {
    return this->mInFilePtr == rhs.mInFilePtr;
}

bool result_iterator::operator!=(const result_iterator& rhs){
    return this->mInFilePtr != rhs.mInFilePtr;
}
 */
