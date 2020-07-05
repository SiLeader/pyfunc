cmake_minimum_required(VERSION 3.10)


include(${PROJECT_SOURCE_DIR}/cmake/DownloadProject/DownloadProject.cmake)

download_project(
        PROJ googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_executable(pyfunc_test range.cc enumerate.cc)
target_link_libraries(pyfunc_test gtest_main)
target_include_directories(pyfunc_test PRIVATE ../include ${GTEST_INCLUDE_DIRS})
target_compile_options(pyfunc_test PRIVATE -Wall -Wextra -Wold-style-cast -Wcast-align -Wcast-qual -Wconversion -Wpedantic -Wpointer-arith -Wreorder -Wshadow -Wsign-promo -Wsuggest-override)

include(GoogleTest)
gtest_add_tests(TARGET pyfunc_test)
