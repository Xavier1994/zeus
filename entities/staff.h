/*
 Created by lenovo on 2015/12/5.
*/

#ifndef ZEUS_STAFF_H
#define ZEUS_STAFF_H

#include <string>
#include <vector>

#include "../util/orm_helper.h"
#include "../constants/config.h"
#include "entity.h"


namespace zeus{

    class Staff : public Entity {
        std::string staff_id;
        std::string login_id;
        std::string name;
        Gender gender;
        uint rank_id;
        uint hotel_id;
        uint department_id;
    public:
        Staff(const std::string& staff_id_,
              const std::string& login_id_,
              const std::string& name_,
              Gender gender_,
              uint rank_id_,
              uint hotel_id_,
              uint department_id_):staff_id(staff_id_),
                                   login_id(login_id_),
                                   name(name_),
                                   gender(gender_),
                                   rank_id(rank_id_),
                                   hotel_id(hotel_id_),
                                   department_id(department_id_){};

        Staff(const std::vector<std::string>& result);

        Staff(const std::string& content);

        virtual std::vector<std::string> AsVector();

        virtual std::string AsString();

        virtual ~Staff();

        std::string GetStaffID(){return this->staff_id;}

        std::string GetLoginID(){return this->login_id;}

        std::string GetName(){return this->name;}

        Gender GetGender(){return this->gender;}

        uint GetRankID(){return this->rank_id;}

        uint GetHotelID(){return this->hotel_id;}

        uint GetDepartmentID(){return this->department_id;}

    };
}


#endif //ZEUS_STAFF_H
