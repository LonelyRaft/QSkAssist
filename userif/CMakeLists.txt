
add_library(${QSKA_USERIF} 
    mainview.cpp
    sktree.cpp
    skmenu.cpp
    skdata.cpp
    skdialog.cpp)
target_link_libraries(${QSKA_USERIF} 
    PUBLIC Qt5::Widgets
    PUBLIC Qt5::Core
    PUBLIC Qt5::Network)
target_include_directories(${QSKA_USERIF} 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${QSKA_USERIF} 
    PUBLIC "${PROJECT_SOURCE_DIR}/logic")
