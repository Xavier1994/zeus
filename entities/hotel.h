/*
 Created by Xavier on 2015/12/5.
*/

#ifndef ZEUS_HOTEL_H
#define ZEUS_HOTEL_H

#include <string>
#include <vector>

#include "entity.h"

namespace zeus{

    class Hotel : public Entity {
        std::string hotel_id;
        std::string hotel_name;
        std::string address;
        std::string tel;
    public:
        Hotel(const std::string& hotel_id_,
              const std::string& hotel_name_,
              const std::string address_,
              const std::string& tel_):hotel_id(hotel_id_),
                                       hotel_name(hotel_name_),
                                       address(address_),
                                       tel(tel_){};

        Hotel(const std::vector<std::string>& result);

        Hotel(const std::string& content);

        virtual std::vector<std::string> AsVector();

        virtual std::string AsString();

    };
}


#endif //ZEUS_HOTEL_H
