cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME queue)
project(${PROJECT_NAME})

option(BUILD_TESTS "Build tests" OFF)
option(BUILD_EXAMPLES "Build Examples" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sources/queue.h)
add_definitions(-Wall -std=c++11)
set(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
add_executable(${PROJECT_NAME} ${main})
target_link_libraries(${PROJECT_NAME})

if(BUILD_TESTS)
  hunter_add_package(Catch)
  find_package(Catch CONFIG REQUIRED)

  enable_testing()

  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(tests ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(tests ${PROJECT_NAME} Catch::Catch )

  add_test(NAME test_name COMMAND tests "-s" "-r" "compact" "--use-colour" "yes") 
endif()