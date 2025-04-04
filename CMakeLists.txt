cmake_minimum_required(VERSION 3.26)
project(fork_wait_pipe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fork_wait_pipe
        Pipe.cpp
        Pipe.h)
