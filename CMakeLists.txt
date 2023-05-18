cmake_minimum_required(VERSION 3.24)
project(cowboy_vs_ninja_b)

set(CMAKE_CXX_STANDARD 17)

add_executable(cowboy_vs_ninja_b Demo.cpp sources/Character.hpp sources/Cowboy.hpp sources/Ninja.hpp sources/Point.hpp sources/TrainedNinja.hpp sources/OldNinja.hpp sources/YoungNinja.hpp sources/Team.hpp sources/Team2.hpp sources/SmartTeam.hpp sources/Ninja.cpp sources/Cowboy.cpp sources/Character.cpp sources/OldNinja.cpp sources/Point.cpp sources/TrainedNinja.cpp sources/YoungNinja.cpp sources/Team.cpp sources/Team2.cpp sources/SmartTeam.cpp)
