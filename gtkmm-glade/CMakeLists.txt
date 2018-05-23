# Minimum CMake version required to generate our build system
cmake_minimum_required(VERSION 3.0)

add_definitions("-std=c++1y")

project(GTKmmGlade)

# Use verbose make files
# This option can additionally be controlled by -DCMAKE_VERBOSE_MAKEFILE=ON
set(CMAKE_VERBOSE_MAKEFILE ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# the GResources.cmake module isn't automatically detected
include(${CMAKE_SOURCE_DIR}/cmake/GResources.cmake)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0) # look into FindPkgConfig.cmake,
# it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect

link_directories( ${GTKMM_LIBRARY_DIRS} )

include_directories( ${GTKMM_INCLUDE_DIRS} )

# Add other flags to the compiler like -std+c++11 and etc.
add_definitions(${GTKMM_CFLAGS_OTHER})

# warnings
add_definitions(
    -Wall
    -Wextra
    -Wno-cpp
    -Wmissing-noreturn
    -Wpointer-arith
    -Wcast-align
    -Wwrite-strings
    -Wformat-nonliteral
    -Wformat-security
    -Wswitch-enum
    -Winit-self
    -Wmissing-include-dirs
    -Wundef
    -Wmissing-format-attribute
    -Wno-reorder
    -Wunused
    -Wuninitialized
    -Woverloaded-virtual
    -Wsuggest-attribute=const
    -Wunused-value
    -Wdouble-promotion
    -Wnonnull
    -Wsequence-point
    -Wunused-but-set-parameter
    -Wsizeof-pointer-memaccess
    -Wvarargs
)

# more warnings
if (CMAKE_COMPILER_IS_GNUCC)
    if (GCC_VERSION VERSION_GREATER 4.9 OR GCC_VERSION VERSION_EQUAL 4.9)
        add_definitions(
            -Wconditionally-supported
            -Wdate-time
            -Wdelete-incomplete
            -Wfloat-conversion
        )
    endif()

    if(GCC_VERSION VERSION_GREATER 5.0 OR GCC_VERSION VERSION_EQUAL 5.0)
        add_definitions(
            -Wsuggest-override
            -Wsuggest-final-types
            -Wsuggest-final-methods
            -Wbool-compare
            -Wformat-signedness
            -Wlogical-not-parentheses
            -Wnormalized
            -Wshift-count-negative
            -Wshift-count-overflow
            -Wsized-deallocation
            -Wsizeof-array-argument
        )
    endif()
endif()

# source files to compile
set(SRC_FILES
    src/gtkmm-glade.cpp
)


# compile glib resource files to c code
glib_compile_resources(
    GLIB_RESOURCES
    SOURCE
    ui/glade.gresource.xml
)

add_executable(
    gtkmm-glade
    ${SRC_FILES}
    ${GLIB_RESOURCES}
)

target_link_libraries(gtkmm-glade ${GTKMM_LIBRARIES})
