cmake_minimum_required(VERSION 3.10)

project(
	microlog
 	DESCRIPTION "small C++ logger"
	VERSION 0.0.1
	LANGUAGES CXX
)

option(microlog_BUILD_EXAMPLES "Build microlog examples" OFF)
option(microlog_BUILD_TESTS    "Build microlog tests"    ON)
option(microlog_BUILD_DOCS     "Build microlog doxygen"	 ON)


add_library(
	microlog STATIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src/microlog.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/microlog/microlog.hpp
)

target_include_directories(
	microlog 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(
	microlog
	PUBLIC "$<$<CONFIG:DEBUG>:-DDEBUG -g3>"
)

if(microlog_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(microlog_BUILD_DOCS)
	find_package(Doxygen)

	set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/examples)
	set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${CMAKE_CURRENT_SOURCE_DIR}/Readme.md)

	IF(DOXYGEN_FOUND)
		doxygen_add_docs(doc)
 	else()
		MESSAGE(STATUS "Doxygen not found. Documentation will not be generated")
	endif()
endif()

if(microlog_BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
