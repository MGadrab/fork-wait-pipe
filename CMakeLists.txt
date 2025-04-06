cmake_minimum_required(VERSION 3.26)
project(fork_wait_pipe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fork_wait_pipe
        main.cpp
        usage_of_pipes_forks.h
        pipes.h)
