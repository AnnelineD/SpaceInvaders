cd cmake-build-debug || exit
cmake .. &&
make install &&
cd .. &&
./bin/SpaceInvaders resources/testLevel1.ini resources/testLevel1.ini resources/testLevel2.ini
