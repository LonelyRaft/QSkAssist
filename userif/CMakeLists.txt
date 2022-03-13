
add_library(${QSKA_USERIF} 
    mainview.cpp
    sktree.cpp
    sklist.cpp
    skdata.cpp
    skdialog.cpp)
target_link_libraries(${QSKA_USERIF} PUBLIC Qt5::Widgets)
target_include_directories(${QSKA_USERIF} 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
