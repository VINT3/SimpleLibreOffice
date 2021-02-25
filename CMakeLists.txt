cmake_minimum_required(VERSION 3.5)

project(WriterLO LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLINUX")

#UNO LIBRARY
find_library(LIB1UNO uno_cppuhelpergcc3 HINTS /usr/lib/libreoffice/sdk/lib)
find_library(LIB2UNO uno_cppu HINTS /usr/lib/libreoffice/sdk/lib)
find_library(LIB3UNO uno_salhelpergcc3 HINTS /usr/lib/libreoffice/sdk/lib)
find_library(LIB4UNO uno_sal HINTS /usr/lib/libreoffice/sdk/lib)

set(LIBUNO ${LIB1UNO} ${LIB2UNO} ${LIB3UNO} ${LIB4UNO})


add_executable(WriterLO
    main.cpp
    unowriter.cpp
    unowriter.h
)

target_include_directories(WriterLO PUBLIC /usr/lib/libreoffice/sdk/include) #Path to LO
target_link_libraries(WriterLO PRIVATE ${LIBUNO})
