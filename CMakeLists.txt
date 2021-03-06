cmake_minimum_required(VERSION 3.2)

project(QSkAssist
    VERSION 0.1
    LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Widgets)
find_package(Qt5 COMPONENTS Network)

set(QSKA_LOGIC QSkLogic)
add_subdirectory(logic)
set(QSKA_USERIF QSkUserIF)
add_subdirectory(userif)

add_executable(${PROJECT_NAME}
    main.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC ${QSKA_USERIF}
    PUBLIC ${QSKA_LOGIC})
