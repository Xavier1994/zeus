/*
 Created by Xavier on 2015/12/6.
*/

#include <iostream>
#include <map>

#include "cmd/cmdline.h"
#include "constants/config.h"
#include "csv_parser/result_iterator.h"
#include "csv_parser/csv_parser.h"
#include "writer/csv_writer.h"
#include "util/string_helper.h"
#include "util/file_helper.h"


using namespace std;
using namespace zeus;

// Initialize the FILE_NAME to build the relation between entity and the file path
void Initialize(){
    FILE_NAME["customer"] = CUSTOMER_TABLE;
    FILE_NAME["staff"] = STAFF_TABLE;
    FILE_NAME["hotel"] = HOTEL_TABLE;
    FILE_NAME["room"] = ROOM_TABLE;
    FILE_NAME["region"] = REGION_TABLE;
}


/*
 * Find a vector of string by the table name and the entity id
 * @param table, the name of the table to store the data
 * @param id, the id of entity
 * @return the content of a entity, use the format of vector<string>
 */
vector<string> FindById(const string& table, const string& id){
    CSVParser csvParser(FILE_NAME[table]);
    vector<string> result = csvParser.find(id, 0);
    return result;
}

/*
 * Write content to a data tanle
 * @param table, table name
 * @param content, the content to write
 * @return the mark to indicate if the operation is successful
 */
bool WriteTotable(const string& table, const string& content){
    CSVWriter csvWriter(FILE_NAME[table], ios::app);
    return csvWriter.write("\n" + content);
}

/*
 * Delete an entity by entity id
 * @param table, table name
 * @param id, the entity's id
 * @return the mark to indicate if the operation is successful
 */
bool DeleteById(const string& table, const string& id){
    CSVWriter csvWriter(OUTPUT, ios::out);
    CSVParser csvParser(FILE_NAME[table]);
    result_iterator itr = csvParser.begin();
    for(; *(itr.getPtr()); ++itr){
        vector<string> result = *itr;
        if(result[0] != id){
            csvWriter.write(StringHelper::StringCompose(result, ',') + "\n");
        }
    }
    return true;
}

/*
 * Updata an entity by its id
 * @param table, table name
 * @param id, the entity id
 * @param content, the content will be updated
 * @mark to indicate if the operation is successful
 */
bool UpdateById(const string& table, const string& id, const string& content){
    CSVWriter csvWriter(OUTPUT, ios::in);
    CSVParser csvParser(FILE_NAME[table]);
    result_iterator itr = csvParser.begin();
    for(; *(itr.getPtr()); ++itr){
        vector<string> result = *itr;
        if(result[0] != id){
            csvWriter.write(StringHelper::StringCompose(result, ',') + "\n");
        }
        else{
            csvWriter.write(content + "\n");
        }
    }
    return true;
}


int main(int argc, char *argv[])
{
    Initialize();

    // Initialize the cmdline parser and add some command to it
    cmdline::parser cmd_parser;

    // indicate the operation on table, can be CRUD
    cmd_parser.add<string>("operation", 'o', "operation on database", true,
                           "", cmdline::oneof<string>("create","update","read","delete"));

    // the table name of data
    cmd_parser.add<string>("table", 't', "table name", true,
                           "", cmdline::oneof<string>("staff","customer","hotel","room","region"));

    // the id for entity
    cmd_parser.add<string>("id", 'i', "id of entity", false, "");

    // the content will be written
    cmd_parser.add<string>("content", 'c', "content of a entity", false, "");

    // help message
    cmd_parser.add("help", 0, "print the help message");

    cmd_parser.parse_check(argc, argv);

    if(argc == 1 || cmd_parser.exist("help")){
        cerr << cmd_parser.usage();
        return 0;
    }

    cout << cmd_parser.get<string>("operation") << " on "
         << cmd_parser.get<string>("table") << " table " << endl;


    // read operation, create operation, delete operation, update operation
    if(cmd_parser.get<string>("operation") == "read" && cmd_parser.exist("id")){
        cout << "The id for entity is : " << cmd_parser.get<string>("id") <<endl;
        cout << "result : " << endl;
        vector<string> result = FindById(cmd_parser.get<string>("table"), cmd_parser.get<string>("id"));
        if(result.empty())
            cout << "There is no entity for " << cmd_parser.get<string>("id") <<endl;
        else
            copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
    }
    else if(cmd_parser.get<string>("operation") == "create" && cmd_parser.exist("content")){
        bool isWrite = WriteTotable(cmd_parser.get<string>("table"),cmd_parser.get<string>("content"));
        if(isWrite)
        {
            cout << "Successfully write to " << cmd_parser.get<string>("table") << "table" << endl
                 << "content : " << endl << cmd_parser.get<string>("content");
        }
        else{
            cout << "Failed to write to " << cmd_parser.get<string>("table") << endl;
        }
    }
    else if(cmd_parser.get<string>("operation") == "delete" && cmd_parser.exist("id")){
        bool isDelete = DeleteById(cmd_parser.get<string>("table"),cmd_parser.get<string>("id"));
        FileHelper::SwapFilesContent(OUTPUT,FILE_NAME[cmd_parser.get<string>("table")]);
        if(isDelete){
            cout << "Successfully delete"  << "the entity of id " << cmd_parser.get<string>("id") << endl;
        }
        else{
            cout << "Failed to delete" << endl;
        }
    }
    else if(cmd_parser.get<string>("operation") == "update" &&
            cmd_parser.exist("id") &&
            cmd_parser.exist("content")){
        bool isUpdate = UpdateById(cmd_parser.get<string>("table"),
                                   cmd_parser.get<string>("id"),
                                   cmd_parser.get<string>("content"));
        FileHelper::SwapFilesContent(OUTPUT,FILE_NAME[cmd_parser.get<string>("table")]);
        if(isUpdate){
            cout << "Successfully update" <<endl;
        }
        else{
            cout << "Failed to update" << endl;
        }
    }

    return 0;
}


