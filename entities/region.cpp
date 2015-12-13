/*
 Created by lenovo on 2015/12/5.
*/

#include <vector>
#include <string>

#include "region.h"
#include "../util/string_helper.h"
#include "../constants/config.h"
#include "../util/orm_helper.h"

using namespace std;
using namespace zeus;

zeus::Region::Region(const std::vector<std::string> &result) {
    this->region_id = StringHelper::StringToUnsignedInt(result[0]);
    this->region_id = Place::CheckLoc(result[1]);
    this->manager_id = result[2];
}

zeus::Region::Region(const std::string &content) {
    vector<string> result = StringHelper::StringSplit(content, ' ');
    Region tmp(result);
    (*this) = tmp;
}

zeus::Region::~Region(){ }

std::vector<std::string> zeus::Region::AsVector() {
    vector<string> result(3);
    result[0] = this->region_id;
    result[1] = Place::ToString(this->region_name);
    result[2] = this->manager_id;
    return result;
}

std::string zeus::Region::AsString() {
    return StringHelper::StringCompose(this->AsVector(),',');
}
