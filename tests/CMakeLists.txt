
include(kolibriexe)

add_kolibri_executable(micrologTest ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

target_link_libraries(micrologTest PRIVATE microlog)

add_test(
    NAME micrologTest
    COMMAND micrologTest
)
