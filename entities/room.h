/*
 Created by lenovo on 2015/12/5.
*/

#ifndef ZEUS_ROOM_H
#define ZEUS_ROOM_H

#include <vector>
#include <string>

#include "../util/string_helper.h"
#include "../util/orm_helper.h"
#include "entity.h"

namespace zeus{

    class Room : public Entity{
        std::string room_id;
        Place::Location room_location;
        RoomType::Type room_type;
        std::string price;
        PriceUnit::Unit price_unit;
        bool available;
        std::string time_range;
    public:
        Room(const std::string& room_id_,
             Place::Location room_location_,
             RoomType::Type room_type_,
             std::string price_,
             PriceUnit::Unit price_unit_,
             bool available_,
             const std::string& time_range_):room_id(room_id_),
                                             room_location(room_location_),
                                             room_type(room_type_),
                                             price(price_),
                                             price_unit(price_unit_),
                                             available(available_),
                                             time_range(time_range_){};

        Room(const std::vector<std::string>& result);

        Room(const std::string& content);

        ~Room();

        virtual std::vector<std::string> AsVector();

        virtual std::string AsString();

    };
}


#endif //ZEUS_ROOM_H
