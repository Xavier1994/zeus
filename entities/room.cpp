/*
 Created by lenovo on 2015/12/5.
*/

#include <vector>
#include <string>

#include "room.h"
#include "../util/orm_helper.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;

Room::Room(const std::vector<std::string> &result) {
    Room tmp(result[0],
               Place::CheckLoc(result[1]),
               RoomType::CheckRoomType(result[2]),
               result[3],
               PriceUnit::CheckPriceUnit(result[4]),
               result[5] == "yes",
               result[6]);
    (*this) = tmp;
}

Room::Room(const std::string &content) {
    vector<string> result = StringHelper::StringSplit(content, ' ');
    Room tmp(result);
    (*this) = tmp;

}

std::vector<std::string> Room::AsVector() {
    vector<string> result(7);
    result[0] = this->room_id;
    result[1] = Place::ToString(this->room_location);
    result[2] = RoomType::ToString(this->room_type);
    result[3] = this->price;
    result[4] = PriceUnit::ToString(this->price_unit);
    result[5] = (this->available ? "yes" : "no");
    result[6] = this->time_range;
    return result;
}

std::string zeus::Room::AsString() {
    return StringHelper::StringCompose(this->AsVector(),',');
}

Room::~Room(){}
