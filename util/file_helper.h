/*
 Created by Xavier on 2015/12/6.
*/

#ifndef ZEUS_FILE_HELPER_H
#define ZEUS_FILE_HELPER_H

#include <string>
#include <fstream>
#include <iostream>

namespace zeus{

    struct FileHelper {
        /*
         * From outfile to infile
         * @param inFileNmae, input file name
         * @param outFileName, output file name
         * @return bool, indicate if the operation is successful
         */
        static bool SwapFilesContent(const std::string& inFileName, const std::string& outFileName){
            std::ifstream inFile(inFileName);
            std::ofstream outFile(outFileName, std::ios::out);
            if((outFile.is_open()) && (inFile.is_open())){
                while(inFile){
                    std::string tmp;
                    getline(inFile, tmp, '\n');
                    outFile << tmp << "\n";
                }
                inFile.close();
                outFile.close();
                return true;
            }
            return false;
        }
    };
}


#endif //ZEUS_FILE_HELPER_H
