//
// Created by lenovo on 2015/12/4.
//

#ifndef ZEUS_STRING_HELPER_H
#define ZEUS_STRING_HELPER_H

#include <vector>
#include <string>
#include "../constants/config.h"

namespace zeus {

    struct StringHelper {

        /*
         * Slpit a string to a vector of string
         * @param content, the string want to split
         * @param separator, the separator of string
         * @return vector<string>, thr result
         */
        static std::vector<std::string> StringSplit(std::string content, char separator){
            std::vector<std::string> result;
            content += separator;
            size_t start = 0;
            for(size_t i = 0; i<content.size(); ++i){
                if(content[i] == separator){
                    result.push_back(content.substr(start, i - start));
                    start = i+1;
                }
            }
            return result;
        }

        /*
         * Compose a string
         * @param result,  the vector of string want to compose
         * @param separator
         * @return string, result
         */
        static std::string StringCompose(const std::vector<std::string> &result, char separator){
            std::string content("");
            for(const std::string& word : result){
                content += word;
                content += separator;
            }
            content.pop_back();
            return content;
        }

        /*
         * trasfer a string to unsigned int
         * @param number, represented by string
         * @return unsign int, the transfer result
         */
        static unsigned int StringToUnsignedInt(std::string number){
            unsigned int result = 0;
            for(char& ch : number){
                if(ch < '0' || ch > '9'){
                    return 0;
                }
                result = result*10 + (ch - '0');
            }
            return result;
        }

        /*
         * transfer a unsigned int to string
         * @param num
         * @return string
         */
        static std::string UnsignIntToString(uint num) {
            return TOSTRING(num);
        }
    };
}


#endif //ZEUS_STRING_HELPER_H
