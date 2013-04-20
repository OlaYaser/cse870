CSE 870 MiniProject Part 1

If any problems arise during compilation, please contact Scott Klum at scott.klum@gmail.com so he can help. I assume all users of this system have the latest versions of llvm, and clang (default compiler front and back ends used by OSX). GCC should work fine too.

1. Download CMake from http://www.cmake.org/files/v2.8/cmake-2.8.10.2-Darwin64-universal.dmg.  Add the command line tools when prompted.

2. Download Qt5 from http://releases.qt-project.org/qt5/5.0.1/qt-mac-opensource-5.0.1-clang-offline.dmg.  Follow installation instructions.

3. From the terminal, within the PBS folder make a directory called build and cd into that directory, like so: 
$ mkdir build
$ cd build

4. Run cmake from the terminal then make, like so:
$ cmake -D CMAKE_PREFIX_PATH=~/Qt5.0.1/5.0.1/clang_64 ..
$ make

5. Cd into the app directory that is created from the execution of make. Run pbs_demo, like so:
$ ./pbs_demo

6. That's it!  Enjoy our simulation.

Usage:
Pedestrians can be created by clicking anywhere on the screen.  They are given an initial speed and direction randomly.  Initially, the car has a speed of 5 mph and only travels in the positive y direction.  You can increase or decrease the speed of the car with the up and down arrows, respectively.  If the pedestrians come within the outer range of the sensor, the light on the car will turn orange.  This indicates that an audio alarm has been set off.  If the pedestrian comes within the inner radius of the sensor, the prevention mechanism is triggered.  This stops the car and you'll notice all the pedestrians stop and make sure everything is okay!    Clicking reverse will start the simulation again (with the car at 0 mph), and the pedestrian in the way will be removed.
