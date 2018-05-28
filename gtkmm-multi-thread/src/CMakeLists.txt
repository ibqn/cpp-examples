link_directories( ${GTKMM_LIBRARY_DIRS} )

include_directories( ${GTKMM_INCLUDE_DIRS} )

# Add other flags to the compiler like -std+c++11 and etc.
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(
    gtkmm-multi-thread
    main.cpp
    example-window.cpp
    example-window.hpp
    example-worker.cpp
    example-worker.hpp
)

target_link_libraries(gtkmm-multi-thread ${GTKMM_LIBRARIES} -pthread)
