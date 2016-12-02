
# gl-engine

An experimental C++ Graphics engine using OpenGL and TBB.

## Instructions to build

First ensure you have the following libraries:

## On linux:

`cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libtbb-dev`


Type the following:

`mkdir build`
`cd build`
`cmake ..`
`make all`

to build the project.

##On Windows:
Windows should already have the required packages through the correct drivers installation. However, you will need 
to download Cmake and TBB (Threading Building Blocks), making sure that the compilation can find TBB in the environment. 
This can be done by downloading the TBB files from threadingbuildingblocks.com and setting up the include, lib, and linker correctly
in VS.

