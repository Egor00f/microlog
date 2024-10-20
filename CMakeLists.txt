cmake_minimum_required(VERSION 3.10)

project(
	microlog
 	DESCRIPTION "small C++ logger"
	VERSION 0.0.1
	LANGUAGES CXX
)

option(microlog_BUILD_EXAMPLES "Build microlog examples" ON)
option(microlog_BUILD_TESTS    "Build microlog tests"    ON)
option(microlog_BUILD_DOCS     "Build microlog doxygen"	 ON)

set(KOLIBRIOS_REPO	${CMAKE_CURRENT_SOURCE_DIR}/../../kolibrios)

get_filename_component(REPO ${KOLIBRIOS_REPO} REALPATH)
set(KOLIBRIOS_REPO ${REPO})
if(EXISTS "${REPO}")
	message(STATUS "KOLIBRIOS REPO Found: ${KOLIBRIOS_REPO}")
else()
	message(FATAL_ERROR "KOLIBRIOS Repo not found, try set KOLIBRIOS_REPO or download kolibros repo")
endif()

add_library(
	microlog STATIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src/microlog.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/microlog/microlog.hpp
)

target_include_directories(
	microlog 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
 	PUBLIC ${KOLIBRIOS_REPO}/contrib/sdk/sources/newlib/libc/include
	PUBLIC PUBLIC ${KOLIBRIOS_REPO}/contrib/sdk/sources/libstdc++-v3/include
)

if(microlog_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(microlog_BUILD_DOCS)
	find_package(Doxygen)

	set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/examples)

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
