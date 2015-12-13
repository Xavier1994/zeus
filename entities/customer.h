/*
 Created by Xavier on 2015/12/5.
*/

#ifndef ZEUS_CUSTOMER_H
#define ZEUS_CUSTOMER_H

#include "../util/orm_helper.h"
#include "entity.h"

namespace zeus{

    class Customer : public Entity {
        std::string customer_id;
        std::string login_id;
        Gender gender;
        Birthday birthday;
        std::string nationnality;
        std::string passport_no;
        std::string address;
        std::string email;
        std::string tel;
    public:
        Customer(const std::string& customer_id_,
                 const std::string& login_id_,
                 Gender gender_,
                 Birthday birthday_,
                 const std::string& nationnality_,
                 const std::string& passport_no_,
                 const std::string& address_,
                 const std::string& email_,
                 const std::string& tel_):customer_id(customer_id_),
                                          login_id(login_id_),
                                          gender(gender_),
                                          birthday(birthday_),
                                          nationnality(nationnality_),
                                          passport_no(passport_no_),
                                          address(address_),
                                          email(email_),
                                          tel(tel_){};


        Customer(const std::string& content);

        Customer(const std::vector<std::string>& content);

        virtual ~Customer();

        virtual std::vector<std::string> AsVector();

        virtual std::string AsString();

        std::string GetCustomerID(){return this->customer_id;}

        std::string GetLoginID(){return this->login_id;}

        Gender GetGender(){return this->gender;}

        Birthday GetBirthDay(){return this->birthday;}

        std::string GetNationnality(){return this->nationnality;}

        std::string GetPassportNo(){return this->passport_no;}

        std::string GetAddress(){ return this->address;}

        std::string GetEmail(){return this->email;}

        std::string GetTel(){return this->tel;}


    };
}


#endif //ZEUS_CUSTOMER_H
