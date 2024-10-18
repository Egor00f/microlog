cmake_minimum_required(VERSION 3.10)

project(
	microlog
	VERSION 0.0.1
	LANGUAGES CXX
)

option(microlog_BUILD_EXAMPLES "Build microlog examples" ON)
option(microlog_BUILD_TESTS "Build microlog doxygen" ON)
option(microlog_BUILD_DOCS "Build microlog doxygen" ON)


add_library(microlog STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/microlog.cpp)

target_include_directories(microlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(microlog_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(microlog_BUILD_DOCS)
	find_package(Doxygen)

	set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/examples)

	doxygen_add_docs(doc)
endif()

if(microlog_BUILD_TESTS)
	#add_subdirectory(tests)
endif()
