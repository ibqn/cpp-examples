# Minimum CMake version required to generate
# our build system
cmake_minimum_required(VERSION 3.0)

# Name of our Project
project(MyProject)

# add_executable creates an executable with
# The given name.
add_executable(hello hello-world.cpp)
