# Toy Robot
Simple Toy Robot that can move in a 5x5 table.

# Notes
This project was developed using Codeblocks 20.03 with GoogleTest

# Dependencies
- Codeblocks, download and install from: https://www.codeblocks.org/downloads/binaries/ -> Select codeblocks-20.03-setup.exe
- Google Test, download (as zip) from: https://github.com/google/googletest
- Cmake, download and install from: https://cmake.org/download/ -> Select cmake-3.22.2-windows-x86_64.msi

# Installation Notes
## Setup for Google Test
- Clone the project into any directory
- Put google-test.zip in the same directory and extract it. Your project structure should look like this:
  - googletest-main.zip
  - /googletest-main
  - /toy_robot
- Rename /googletest-main to /gtest and put it inside /toy_robot
- The project structure of /toy_robot should now look like this:
  - /.git
  - /gtest
  - /ToyRobot
  - /.gitignore
  - /README.md
  - /test_data.txt
- Next Open CMake (cmake-gui)
- Click on the [Browse Source...] button and select /gtest
- Click on the [Browse Build...] button and select /gtest
- Click on [Configure]
- A dialog will open prompting the user to select a generator.
  - From drop down select "Codeblocks -MinGW Makefiles"
  - Select "Use default native compilers"
  - Click Finish
- Afterwards a list of Entries will be generated. Make sure that following entries are checked:
  - BUILD_GMOCK
  - INSTALL_GTEST
- Click Generate to finish.

## Linking Google Test to Codeblocks
- Open Codeblocks.
- Open the following projects: ToyRobot.cbp and googletest-distribution.cbp. These can be found under:
  - /ToyRobot
    - /ToyRobot.cbp
  - /gtest
    - /googletest-distribution.cbp
- In Codeblocks, Right-click on [googletest-distribution] and make it the active project then Build (Ctrl + F9) it. This creates the libraries needed for gtest and gmock
- Afterwards, Right-click on [ToyRobot] and make it the active project, Build (Ctrl + F9) and Run (Ctrl + F10) or Build and Run (F9).
- A console application should open up and you can now use the ToyRobot applicaition!.

## Additional Installation Notes
- I have taken the liberty and automatically linked the GTest libraries to the ToyRobot project, should there be any issues here follow the following steps:
- In Codeblocks, Right Click on [ToyRobot] and select [Build options...]
- A dialog box will appear, Click on the [Linker settings] tab. Here we will be adding the libraries for gtest and gmock.
- Simply click on add and locate where the libgmock.a and libgtest.a are stored. If you followed the instructions above they should simply be located at /gtest/lib/
- Then go to the [Search directories] tab and add the includes for gtest and gmock They can be found at the following locations:
  - gtest: /gtest/googletest/include
  - gmock: /gtest/googlemock/include
- Click Ok, and you should now be able to compile and run it.

## How to Run Tests
- Pre-requisite: You have followed the instructions above.
- To Run the tests, open the [ToyRobot] project. The project structure should look something like this:
  - ToyRobot (project)
  - /Sources
    - /src
    - main.cpp
    - tests.cpp 
  - /Headers
- Right click on main.cpp and select [Options], click on [Disable Both] (Compile file and Link file should now be unchecked)
- Right click on tests.cpp and select [Options], click on [Enable Both] (Compile file and Link file should now be checked)
- Build and Run, this should now run the tests included in ToyRobot. To re-build the application simply reverse the last 2 steps. 
