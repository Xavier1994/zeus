/*
 Created by lenovo on 2015/12/5.
*/

#include <vector>
#include <string>

#include "hotel.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;

zeus::Hotel::Hotel(const std::vector<std::string> &result) {
    Hotel tmp(result[0],
                result[1],
                result[2],
                result[3]);
    (*this) = tmp;
}

zeus::Hotel::Hotel(const std::string &content) {
    vector<string> result = StringHelper::StringSplit(content, ',');
    Hotel tmp(result);
    (*this) = tmp;
}

std::vector<std::string> zeus::Hotel::AsVector() {
    vector<string> result(4);
    result[0] = this->hotel_id;
    result[1] = this->hotel_name;
    result[2] = this->address;
    result[3] = this->tel;
    return result;
}

std::string zeus::Hotel::AsString() {
    return StringHelper::StringCompose(this->AsVector(),',');
}
