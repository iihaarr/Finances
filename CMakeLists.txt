cmake_minimum_required(VERSION 3.14)

project(finances LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(Qt5_DIR "C:/Qt/Qt5.11.0/5.11.0/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 5.11.0 COMPONENTS Quick Qml Widgets REQUIRED)

#PUBLIC_HEADERS
file(GLOB_RECURSE PUBLIC_ENTITIES_HEADERS ./include/finances/entities/*.hpp)
file(GLOB_RECURSE PUBLIC_UTILS_HEADERS ./include/finances/utils/*.hpp)
file(GLOB_RECURSE PUBLIC_STORAGE_HEADERS ./include/finances/storage/*.hpp)

#PRIVATE_HEADERS
file(GLOB_RECURSE PRIVATE_ENTITIES_HEADERS ./src/finances/entities/*.hpp)
file(GLOB_RECURSE PRIVATE_STORAGE_HEADERS ./src/finances/storage/*.hpp)
file(GLOB_RECURSE PRIVATE_MODELS_HEADERS ./src/finances/models/*.hpp)

#SOURCE FILES
file(GLOB_RECURSE SOURCE_STORAGE ./src/finances/storage/*.cpp)
file(GLOB_RECURSE SOURCE_ENTITIES ./src/finances/entities/*.cpp)
file(GLOB_RECURSE SOURCE_MODELS ./src/finances/models/*.cpp)

#UI QML
file(GLOB_RECURSE UI_FILES ./ui/*.qml)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${Qt5Gui_DEFINITIONS})
qt5_add_resources(QT_RESOURCES ui/qml.qrc)

source_group("Header Files\\Public\\Entities" FILES ${PUBLIC_ENTITIES_HEADERS})
source_group("Header Files\\Public\\Utils" FILES ${PUBLIC_UTILS_HEADERS})
source_group("Header Files\\Public\\Storage" FILES ${PUBLIC_STORAGE_HEADERS})

source_group("Header Files\\Entities" FILES ${PRIVATE_ENTITIES_HEADERS})
source_group("Header Files\\Storage" FILES ${PRIVATE_STORAGE_HEADERS})
source_group("Header Files\\Models" FILES ${PRIVATE_MODELS_HEADERS})
	
source_group("Source Files\\Storage" FILES ${SOURCE_STORAGE})
source_group("Source Files\\Entities" FILES ${SOURCE_ENTITIES})
source_group("Source Files\\Models" FILES ${SOURCE_MODELS})
	
source_group("Resources Files" FILES ${UI_FILES})

add_executable(${PROJECT_NAME} 
#HEADERS
${PUBLIC_ENTITIES_HEADERS} 
${PUBLIC_UTILS_HEADERS} 
${PRIVATE_ENTITIES_HEADERS} 
${PUBLIC_STORAGE_HEADERS}
${PRIVATE_STORAGE_HEADERS}
${PRIVATE_MODELS_HEADERS}
#SOURCES
${SOURCE_STORAGE} 
${SOURCE_ENTITIES}
${SOURCE_MODELS}
./src/main.cpp
#UI
${UI_FILES}
${QT_RESOURCES}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME} Qt5::Quick Qt5::Qml Qt5::Widgets)

target_include_directories(${PROJECT_NAME} 
PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include 
PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
PRIVATE ${Qt5Widgets_INCLUDE_DIRS}
PRIVATE ${QtQml_INCLUDE_DIRS}
PRIVATE ${Qt5Gui_INCLUDE_DIRS}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Qml> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Network> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Quick> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)