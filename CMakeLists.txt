cmake_minimum_required(VERSION 3.19)
project(Proyecto_II_Server_CE2103)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto_II_Server_CE2103 main.cpp src/BPGame/Components/Field.h src/BPGame/BPManager.h src/BPGame/Pathfinding/Pathfinding.h src/BPGame/Pathfinding/Route.h src/BPGame/Components/Ball.h src/BPGame/Components/Player.h src/BPGame/Components/GameSettings.h src/BPGame/Structures/Matrix.h src/BPGame/Structures/LinkedList.h)