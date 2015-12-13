# Zeus
>Zeus is the sky and thunder god in ancient Greek religion, who ruled as king of the gods of Mount Olympus. So I use it to name this product to indicate this software is for helping people managing the hotel’s affairs for every aspects. With this software Managers can grasp of each hotel’s condition and make decisions to run the hotel.     Receptionist can handle the hotel’s daily affairs. Customers can also make use of it to have resevation and get service. There are some features listed below    
* Effective sales analysis and build strong sales strategy 
* Quickly find each hotel’s weakness point 
* The membership intergrating system can stimulate 
* Effective management 
* Scientific performance assessmen  Clearly separate the work between system and business 

### Requirements 
#### customer 
>This part is a web application for customer to book the room, it provides 
some functions listed below 
* Reserve 
* Cancel the reservation and ask a refund 
* Modify the reservation and if needed ask a refund 
* Check the consuming history 
* Book the room service  Give the feedback 
#### receptionist 
>This part is a software to help receptionists to finish thr managing job 
* Check the resevation and service request 
* Check out with customer 
* Manage the assets of room 
* Assign the room 
* Release the room 
* Give the consuming points to customers 
* Arrage for cleaning up  Check the reservation history 
#### manager 
>This part is a software to help managers finish their job 
* Arrange the receptionists’ work 
* Supervising function 
* manage the assets of hotel 
* manage the finance of hotel 
* Decide the strategy of operating 
* Query the booking information 
* Analyze the booking information 
* Give feedback on performance of staffs 
* Human resources management  manage staffs’ account 

### version
>1.0.0

### Tech
> all of the code is written by C++

### Tools
>zeus use these tools to help build
* gcc 4.8.2(support C++11)
* cmake
* clion(a ide for c++)
* git(version control tool)

### Function
> The 1.0.0 version is not complete, so some of its function is still not implemented, there is just some function for manager to manage the information of the hotel, supporting manager to read, check, search and add.
* Read the data from database(I use a csv file to store data)
* Search some information from the database across passing the entity id
* Add some new entity to a specified table

These function can be used by command, this is a CUI program to interact with clients,**command is shown below**
```sh
options:
  -o, --operation    operation on database (string)
  -t, --table        table name (string)
  -i, --id           id of entity (string [=])
  -c, --content      content of a entity (string [=])
      --help         print the help message

```

### Modules
> zeus consist of some modules,these modules is developed for different functions, all of code is written by myself, i did not use the givien code

* **cmd module**, this module is a command line tools, it is developed for build a CUI program
* **constants**, this module if for configing the program
* **csv_parser**, this module is for parse a csv file and read data from the files
* **entities**, this module is built for ORM, it build responsive entity class for database
* **util**, this module is for some helping function,for example, string helper, orm helper, etc...
* **writer**, this module is for writing data to csv files

 
### License 
This is not a free software 

###### Copyright © 2015 Xavier Xie. All rights reserved 





 
  


