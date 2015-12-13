//
// Created by lenovo on 2015/12/5.
//

#ifndef ZEUS_ORM_HELPER_H
#define ZEUS_ORM_HELPER_H

#include <string>

#include "string_helper.h"
#include "../constants/config.h"

namespace zeus{

    enum Gender{
        UNKNOW,
        MALE,
        FEMALE
    };

    struct Place{
        enum Location{
            UNKNOWN,
            NY,
            SH,
            TY
        };

        static Place::Location CheckLoc(const std::string& loc){
            if(loc == "NY")
                return Location::NY;
            else if(loc == "SH")
                return Location::SH;
            else if(loc == "TY")
                return Location::TY;
            else
                return Location::UNKNOWN;
        }

        static std::string ToString(Location loc){
            if(loc == Location::NY)
                return "NY";
            else if(loc == Location::SH)
                return "SH";
            else if(loc == Location::TY)
                return "TY";
            else
                return "";
        }
    };

    struct RoomType{
        enum Type{
            SINGLE,
            DOUBLE,
            SEMIDOUBLE,
            TWIN,
            TRIPLE,
            SUITE,
            OTHER
        };

        static RoomType::Type CheckRoomType(const std::string& roomType){
            if(roomType == "SINGLE")
                return Type::SINGLE;
            else if(roomType == "DOUBLE")
                return Type::DOUBLE;
            else if(roomType == "SEMIDOUBLE")
                return Type::SEMIDOUBLE;
            else if(roomType == "TWIN")
                return Type::TWIN;
            else if(roomType == "TRIPLE")
                return Type::TRIPLE;
            else if(roomType == "SUITE")
                return Type::SUITE;
            else
                return Type::OTHER;
        }

        static std::string ToString(Type roomType){
            if(roomType == Type::SINGLE)
                return "SINGLE";
            else if(roomType == Type::DOUBLE)
                return "DOUBLE";
            else if(roomType == Type::SEMIDOUBLE)
                return "SEMIDOUBLE";
            else if(roomType == Type::TWIN)
                return "TWIN";
            else if(roomType == Type::TRIPLE)
                return "TRIPLE";
            else if(roomType == Type::SUITE)
                return "SUITE";
            else
                return "OTHER";
        }
    };

    struct PriceUnit{
        enum Unit{
            UNKNOWN,
            USD,
            CH,
            JP
        };

        static PriceUnit::Unit CheckPriceUnit(const std::string& priceUnit){
            if(priceUnit == "USD")
                return Unit::USD;
            else if(priceUnit == "CH")
                return Unit::CH;
            else if(priceUnit == "JP")
                return Unit::JP;
            else
                return Unit::UNKNOWN;
        }

        static std::string ToString(Unit priceUnit){
            if(priceUnit == Unit::USD)
                return "USD";
            else if(priceUnit == Unit::CH)
                return "CH";
            else if(priceUnit == Unit::JP)
                return "JP";
            else
                return "";
        }

    };

    class Birthday{
        uint year;
        uint month;
        uint day;
    public:
        Birthday():year(0),month(0),day(0){};
        Birthday(uint year_, uint month_, uint day_):year(year_),month(month_),day(day_){};
        Birthday(const std::string& birthday);
        uint GetYear(){return this->year;}
        uint GetMonth(){return this->month;}
        uint GetDay(){ return this->day;}
        std::string AsString();
    };

}


#endif //ZEUS_ORM_HELPER_H
