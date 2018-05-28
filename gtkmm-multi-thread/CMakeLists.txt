cmake_minimum_required(VERSION 3.0)

project(GTKmmMultiThread)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_subdirectory(src)
