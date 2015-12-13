/*
 Created by Xavier on 2015/12/5.
*/

#include <vector>
#include <string>

#include "customer.h"
#include "../util/string_helper.h"

using namespace std;
using namespace zeus;

Customer::Customer(const std::vector<std::string> &result) {
    string customer_id = result[0];
    string login_id = result[1];
    Gender gender;
    if(result[2] == "Male")gender = Gender::MALE;
    else if(result[2] == "Female")gender = Gender::FEMALE;
    else gender = Gender::UNKNOW;
    Birthday birthday(result[3]);
    string nationnality = result[4];
    string passport_no = result[5];
    string address = result[6];
    string email = result[7];
    string tel = result[8];
    Customer tmp = Customer(customer_id,
                            login_id,
                            gender,
                            birthday,
                            nationnality,
                            passport_no,
                            address,
                            email,
                            tel);
    (*this) = tmp;
}

Customer::Customer(const std::string &content) {
    vector<string> result = StringHelper::StringSplit(content, ',');
    Customer tmp(result);
    (*this) = tmp;
}

vector<string> Customer::AsVector() {
    vector<string> result(9);
    result[0] = this->customer_id;
    result[1] = this->login_id;
    result[2] = this->gender == Gender::MALE ? "Male":(this->gender == Gender::FEMALE ? "Female":"");
    result[3] = this->birthday.AsString();
    result[4] = this->nationnality;
    result[5] = this->passport_no;
    result[6] = this->address;
    result[7] = this->email;
    result[8] = this->tel;
    return result;
}

string Customer::AsString() {
    return StringHelper::StringCompose(this->AsVector(),',');
}


Customer::~Customer() {}
