/*
 Created by Xavier on 2015/12/5.
*/

#include <vector>
#include <string>

#include "orm_helper.h"
#include "string_helper.h"
#include "../constants/config.h"

using namespace std;
using namespace zeus;

Birthday::Birthday(const std::string &birthday) {
    vector<string> birth = StringHelper::StringSplit(birthday,'/');
    this->year = StringHelper::StringToUnsignedInt(birth[0]);
    this->month = StringHelper::StringToUnsignedInt(birth[1]);
    this->day = StringHelper::StringToUnsignedInt(birth[2]);
}

std::string Birthday::AsString() {
    string content("");
    content += TOSTRING(this->year);
    content +="/";
    content +=TOSTRING(this-month);
    content +="/";
    content +=TOSTRING(this->day);
    return content;
}
