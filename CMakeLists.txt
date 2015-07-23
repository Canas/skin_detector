cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project( skin_detector )
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( src )

set(SOURCES src/skin_detector.cpp src/data.cpp)
#set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")

add_executable( skin_detector ${SOURCES} )
#set_property(TARGET skin_detector PROPERTY CXX_STANDARD 11)
#set_property(TARGET skin_detector PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries( skin_detector ${OpenCV_LIBS} )