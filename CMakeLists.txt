cmake_minimum_required(VERSION 3.3)
project(zeus)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp csv_parser/csv_parser.cpp csv_parser/csv_parser.h util/string_helper.h csv_parser/result_iterator.cpp csv_parser/result_iterator.h writer/csv_writer.cpp writer/csv_writer.h entities/customer.h util/orm_helper.h util/orm_helper.cpp entities/staff.cpp entities/staff.h constants/config.h entities/customer.cpp entities/hotel.cpp entities/hotel.h entities/room.cpp entities/room.h entities/region.cpp entities/region.h entities/entity.h cmd/cmdline.h util/file_helper.h)
add_executable(zeus ${SOURCE_FILES})