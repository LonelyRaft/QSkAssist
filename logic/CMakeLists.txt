
add_library(${QSKA_LOGIC}
    skconfig.cpp)
target_link_libraries(${QSKA_LOGIC}
    PUBLIC Qt5::Network)
target_include_directories(${QSKA_LOGIC} 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

