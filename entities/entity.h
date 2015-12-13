/*
 * Created by lenovo on 2015/12/5.
*/

#ifndef ZEUS_ENTITY_H
#define ZEUS_ENTITY_H

#include <string>
#include <vector>


namespace zeus{

    class Entity {
    public:
        virtual std::string AsString() = 0;
        virtual std::vector<std::string> AsVector() = 0;
        virtual ~Entity(){};
    };

}


#endif //ZEUS_ENTITY_H
