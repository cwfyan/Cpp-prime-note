cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 11)

add_executable(src  main.cpp class/StrBlobPtr.cpp class/StrBlob.cpp 13/StrVec.cpp 13/StrVec.h 13/String.cpp 13/String.h 13/Folder.cpp 13/Message.cpp 13/HasPtr.cpp
        class/Sales_data.cpp )