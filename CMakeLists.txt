cmake_minimum_required(VERSION 3.17)
project(Proyecto_II_Server_CE2103)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(Proyecto_II_Server_CE2103 main.cpp
        src/BPGame/Components/Field.h
        src/BPGame/BPManager.h
        src/BPGame/Pathfinding/Pathfinding.h
        src/BPGame/Pathfinding/Route.h
        src/BPGame/Components/Ball.h
        src/BPGame/Components/Player.h
        src/BPGame/Components/GameSettings.h
        src/util/Structures/Matrix.h
        src/util/Structures/LinkedList.h
        src/util/Json.h
        src/util/Response.h
        src/ServerManager.h
        src/util/Message.h
        src/Socket/Server.h
        src/Socket/Server.cpp src/BPGame/BPManager.cpp)