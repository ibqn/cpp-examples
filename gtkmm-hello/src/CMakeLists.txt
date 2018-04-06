link_directories( ${GTKMM_LIBRARY_DIRS} )

include_directories( ${GTKMM_INCLUDE_DIRS} )

# Add other flags to the compiler like -std+c++11 and etc.
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(
    gtkmm-hello       # name of the executable on Windows will be gtkmm-hello.exe
    gtkmm-hello.cpp
)

target_link_libraries(gtkmm-hello ${GTKMM_LIBRARIES} )
