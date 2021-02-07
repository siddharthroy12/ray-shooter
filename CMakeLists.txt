cmake_minimum_required(VERSION 3.0)
project(rayshooter CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(
    rayshooter 
    src/main.cpp
    src/Node.cpp 
    src/context/GlobalContext.cpp
    src/context/GlobalState.cpp
    src/entities/Bullet.cpp
    src/entities/Enemy.cpp
    src/entities/Player.cpp
    src/screens/GameScreen.cpp
)

target_link_libraries(rayshooter PRIVATE raylib)
target_compile_definitions(rayshooter PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(rayshooter PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
