cd cmake-build-debug || exit
cmake .. &&
make install &&
cd .. &&
./bin/SpaceInvaders resources/Level_3x4_easy.ini resources/Level_3x6_easy.ini resources/Level_4x2_medium.ini
