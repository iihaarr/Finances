cmake_minimum_required(VERSION 3.14)

project(finances LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE PUBLIC_ENTITIES_HEADERS ./include/finances/entities/*.hpp)
if (MSVC)
	source_group("Header Files\\Entities" FILES ${PUBLIC_ENTITIES_HEADERS})
endif()

add_executable(${PROJECT_NAME} ${PUBLIC_ENTITIES_HEADERS} main.cpp)


set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)