cmake_minimum_required(VERSION 3.20)
project(RoundGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(RoundGameProject main.cpp Creature.cpp Creature.h SpecialMove.cpp SpecialMove.h CreaturesList.cpp CreaturesList.h)
