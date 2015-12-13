/*
 Created by lenovo on 2015/12/5.
*/

#include <vector>
#include <string>

#include "staff.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;


Staff::Staff(const std::vector<std::string> &result) {
    Staff tmp(result[0],
                result[1],
                result[2],
                (result[3] == "Male" ? Gender::MALE : (result[3] == "Female" ? Gender::FEMALE : Gender::UNKNOW)),
                StringHelper::StringToUnsignedInt(result[4]),
                StringHelper::StringToUnsignedInt(result[5]),
                StringHelper::StringToUnsignedInt(result[6]));
    (*this) = tmp;
}

Staff::Staff(const std::string &content) {
    vector<string> result = StringHelper::StringSplit(content,',');
    Staff tmp(result);
    (*this) = tmp;
}

std::vector<std::string> Staff::AsVector() {
    vector<string> result(8);
    result[0] = this->staff_id;
    result[1] = this->login_id;
    result[2] = this->name;
    result[3] = (this->gender == Gender::MALE ? "Male" : (this->gender == Gender::FEMALE) ? "Female" : "");
    result[4] = StringHelper::UnsignIntToString(this->rank_id);
    result[5] = StringHelper::UnsignIntToString(this->hotel_id);
    result[6] = StringHelper::UnsignIntToString(this->department_id);
    return result;
}

std::string Staff::AsString() {
    return StringHelper::StringCompose(this->AsVector(),',');
}

Staff::~Staff() {}
