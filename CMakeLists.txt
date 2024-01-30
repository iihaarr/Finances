cmake_minimum_required(VERSION 3.14)

project(finances LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#PUBLIC_HEADERS
file(GLOB_RECURSE PUBLIC_ENTITIES_HEADERS ./include/finances/entities/*.hpp)
file(GLOB_RECURSE PUBLIC_UTILS_HEADERS ./include/finances/utils/*.hpp)
file(GLOB_RECURSE PUBLIC_STORAGE_HEADERS ./include/finances/storage/*.hpp)

#PRIVATE_HEADERS
file(GLOB_RECURSE PRIVATE_ENTITIES_HEADERS ./src/finances/entities/*.hpp)
file(GLOB_RECURSE PRIVATE_STORAGE_HEADERS ./src/finances/storage/*.hpp)

#SOURCE FILES
file(GLOB_RECURSE SOURCE_STORAGE ./src/finances/storage/*.cpp)
file(GLOB_RECURSE SOURCE_ENTITIES ./src/finances/entities/*.cpp)

if (MSVC)
	source_group("Header Files\\Public\\Entities" FILES ${PUBLIC_ENTITIES_HEADERS})
	source_group("Header Files\\Public\\Utils" FILES ${PUBLIC_UTILS_HEADERS})
	source_group("Header Files\\Public\\Storage" FILES ${PUBLIC_STORAGE_HEADERS})

	source_group("Header Files\\Entities" FILES ${PRIVATE_ENTITIES_HEADERS})
	source_group("Header Files\\Storage" FILES ${PRIVATE_STORAGE_HEADERS})
	
	source_group("Source Files\\Storage" FILES ${SOURCE_STORAGE})
	source_group("Source Files\\Entities" FILES ${SOURCE_ENTITIES})
endif()

add_executable(${PROJECT_NAME} 
#HEADERS
${PUBLIC_ENTITIES_HEADERS} 
${PUBLIC_UTILS_HEADERS} 
${PRIVATE_ENTITIES_HEADERS} 
${PUBLIC_STORAGE_HEADERS}
${PRIVATE_STORAGE_HEADERS}
#SOURCES
${SOURCE_STORAGE} 
${SOURCE_ENTITIES}
./src/main.cpp
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} 
PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include 
PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
)