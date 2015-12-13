//
// Created by lenovo on 2015/12/5.
//

#ifndef ZEUS_CONFIG_H
#define ZEUS_CONFIG_H

#include <string>
#include <map>

#define TOSTRING(name) #name

namespace zeus{

    typedef unsigned int uint;

    // the map to store the table name and file path
    static std::map<std::string,std::string> FILE_NAME;

    // the staff table file path
    const static std::string STAFF_TABLE("C:/Users/lenovo/ClionProjects/zeus/input/STAFF_MST.csv");

    // the customer table file path
    const static std::string CUSTOMER_TABLE("C:/Users/lenovo/ClionProjects/zeus/input/CUSTOMER_MST.csv");

    // the hotel table file path
    const static std::string HOTEL_TABLE("C:/Users/lenovo/ClionProjects/zeus/input/HOTEL_MST.csv");

    // the room table file path
    const static std::string ROOM_TABLE("C:/Users/lenovo/ClionProjects/zeus/input/ROOM_MST.csv");

    // the region table file path
    const static std::string REGION_TABLE("C:/Users/lenovo/ClionProjects/zeus/input/REGION_MST.csv");

    // the output file path
    const static std::string OUTPUT("C:/Users/lenovo/ClionProjects/zeus/output/OUTPUT.csv");
}
#endif //ZEUS_CONFIG_H
