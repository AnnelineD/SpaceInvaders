cmake_minimum_required(VERSION 3.12.0)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpaceInvaders main.cpp
        Entity.cpp Entity.h
        SpaceInvadersGame.cpp SpaceInvadersGame.h
        View.cpp View.h
        Controller.cpp Controller.h
        Model.cpp Model.h
        Stopwatch.cpp Stopwatch.h
        Subject.cpp Subject.h
        Observer.cpp Observer.h
        Transformation.cpp Transformation.h)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()