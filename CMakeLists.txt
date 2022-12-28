cmake_minimum_required(VERSION 3.24)
project(SWE_BAJIM_UE05)

set(CMAKE_CXX_STANDARD 20)

add_executable(SWE_BAJIM_UE05 main.cpp content/airline/airline.cpp content/airline/airline.h tests/test_airline_t.cpp tests/test_partlists_t.cpp content/partlist/partlist_t.cpp content/partlist/partlist_t.h)
