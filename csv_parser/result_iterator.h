/*
 Created by Xavier on 2015/12/4.
*/

#ifndef ZEUS_RESULT_ITERATOR_H
#define ZEUS_RESULT_ITERATOR_H

#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

/*
 * This class is a iterator to get the file's content,
 * every time,get one line content of the file and transfer
 * it to a vector of string
 */
namespace zeus{

    class result_iterator : public std::iterator<std::input_iterator_tag,std::vector<std::string>> {
        std::shared_ptr<std::ifstream> mInFilePtr;
        std::vector<std::string> mRes;

    public:
        result_iterator();

        //result_iterator(const std::string& fileName);

        result_iterator(std::ifstream& inFile);

        ~result_iterator();

        result_iterator(const result_iterator& rhs);

        result_iterator& operator=(const result_iterator& rhs);

        const std::vector<std::string>& operator*();

        std::vector<std::string>*operator->();

        result_iterator& operator++();

        result_iterator operator++(int);

        std::shared_ptr<std::ifstream> getPtr();

        /*
        bool operator==(const result_iterator& rhs);

        bool operator!=(const result_iterator& rhs);
        */
    };
}


#endif //ZEUS_RESULT_ITERATOR_H
