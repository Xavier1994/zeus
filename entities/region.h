/*
 Created by lenovo on 2015/12/5.
*/

#ifndef ZEUS_REGION_H
#define ZEUS_REGION_H

#include <string>
#include <vector>

#include "entity.h"
#include "../constants/config.h"
#include "../util/orm_helper.h"

namespace zeus{

    class Region : public Entity{
        std::string region_id;
        Place::Location region_name;
        std::string manager_id;
    public:
        Region(const std::string& region_id_,
               Place::Location region_name_,
               const std::string& manager_id_):region_id(region_id_),
                                               region_name(region_name_),
                                               manager_id(manager_id_){};

        Region(const std::vector<std::string>& result);

        Region(const std::string& content);

        virtual ~Region();

        virtual std::vector<std::string> AsVector();

        virtual std::string AsString();
    };
}


#endif //ZEUS_REGION_H
