cmake_minimum_required(VERSION 3.10)

project(microlog)

option(microlog_BUILD_EXAMPLES "Build examples" ON)
option(microlog_BUILD_DOCS "Build doxygen" ON)


add_library(microlog STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/microlog.cpp)

target_include_directories(microlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(microlog_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(microlog_BUILD_DOCS)

endif()
