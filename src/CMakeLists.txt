add_executable( SpaceInvaders
        ../extern/INIReader.h
        main.cpp
        Bullet.cpp Bullet.h
        Controller.cpp Controller.h
        Enemy.cpp Enemy.h
        Entity.cpp Entity.h
        Model.cpp Model.h
        Observer.h
        ShieldBlock.cpp ShieldBlock.h
        SpaceInvadersGame.cpp SpaceInvadersGame.h
        Sprite.cpp Sprite.h
        Stopwatch.cpp Stopwatch.h
        Subject.cpp Subject.h
        Player.cpp Player.h
        Transformation.cpp Transformation.h
        View.cpp View.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

INSTALL(TARGETS SpaceInvaders DESTINATION ${PROJECT_SOURCE_DIR}/bin)

