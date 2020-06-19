# AVC
## Installation
### Installing Geany
#### Geany for Mac 
#### Geany for Windows
*For any version make sure Geany is installed and can compile, build and run programs*
### Installing SFML
#### Mac 
Install Homebrew by typing this into the terminal.
>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

Once Homebrew is installed, paste this into terminal to install SFML:
>brew install sfml 

Open Geany and under build commands paste these flags after the pre-existing flags. 
>-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network 
#### Windows
First you must install the SFML library from this site: https://www.sfml-dev.org/download/sfml/2.5.1/, if you are running on geany and minGW can sure you download the minGW versions of the library and it's corresponding version (32 bit or 64 bit).

Afterwards, create a folder in your (C:) drive called SFML and move the downloaded zip file into this folder and unzip it.

Now download the AVC_Robot_Windows folder from the top of the page and put them in which ever folder you like.

Open the C:SFML folder and open the folder "include" and copy the file path for it. Then open the makefile file in the AVC_robot folder with geany and paste the file path into the line that starts with "INCLUDE" just after the "-I" and delete the place holder path. Open C:SFML again and open the file "lib" and copy the file path. Paste the lib file path in the line that starts with "LIBS" after "-L" and delete the place holder path.  Repeat this instruction but instead use the makefile file in the AVC_server folder.

Finally, open server3.cpp and robot.cpp in geany and go to "Set Build Commands" which should be located in the "Build" section of the nav bar. In the "Independant commands" in the 1st row, 2nd column change "make" to "mingw32-make".

Instead of using compile, build and run press shift+F9 to make the code. Do this make command for both server3.cpp and robot.cpp and they should  both successfully compile (robot.cpp will give warnings before successfully compiling but that's okay). Then press F5 to run the two .cpp files. Make sure you run server3.cpp first before running robot.cpp or else the program will not work.

If you try and compile the two .cpp files but are unsuccessful try and delete the server3.o file from the AVC_server folder and the robot.o from the AVC_robot folder.

### Downloading Our Code
Downloading code is done by cloning our github repository. In Github Desktop, we can do this by going to Current Repository > Add > URL and paste in https://github.com/ENGR101-AVC/AVC.git

### Compile Build and Run (Mac)
Our make file does all of these steps automatically by executing make (MAC) or mingw-make(Windows).
To run programs, first you have to compile, build and then run (F8, F9 and then F5).
To make the robot work, you have to first compile, build and run the server3.cpp file. Then you have to compile, build and run the robot.cpp file. 

## Initial Plan
Team Name: Team 37

Github: https://github.com/ENGR101-AVC
### Team Members & Contact Info:
**Vincent Alvarez**
Email: alvarevinc@myvuw.ac.nz

**Dilitha Wijayapala**
Email: wijayagama@myvuw.ac.nz

**Shruti Raja**
Email: rajashru@myvuw.ac.nz

**Harper Doak**
Email: doakharp@myvuw.ac.nz

**Samuel Marshall**
Email: marshasamu@myvuw.ac.nz

### Communication tool:
Discord

### Roles:
**Shruti Raja** - Project Manager (organising team meetings, reporting regularly on progress)

**Sam Marshall** - Software Architect (writing core code and extending functionality)

**Harper Doak** - Software Architect (writing core code and extending functionality)

**Dilitha Wijayapala** - Software writing, testing and documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)

**Vincent Alvarez** - Software writing, testing and documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)

### Plan and Milestones
|Date|Objectives|Due Date|Item Due|Conflicts|Tasks|
|----|----|-----|----|---|---|
|1/06|Start the project|4 June|Testing Code|...|**[All]** Complete AVC Plan<br>**[All]** Install library and run testing code|
|4/06|Core code|June 19|Core Code - June 7||**[Sam]** **[Harper]** Core Code Completed by 6th<br>**[Vincent]** **[Dilitha]** Core Code fully tested by 7th and test cases documented<br>**[Shruti]** Plan meetings, set up report<br>**[Dilitha]** Write up installation guide|
|8/06|Write up weekly report||||**[All]** Meet up and discuss weekly progress, keep personal progess logs up to date. |
|9/06|Completion code|June 19|Completion Code - June 14||**[Sam]** **[Harper]** Completion Code completed by 13th<br>**[Vincent]** **[Dilitha]** Completion Code fully tested and documented by 14th<br>**[Shruti]** Plan next weekly meeting, continue writing report|
|13/06|Finish completion begin challenge|June 19th|Challenge code||**[Sam]** **[Harper]** Challenge code completed by 18th or 19th<br>**[Vincent]** **[Dilitha]** Test code as soon as possible as well as helping Sam and Harper with challenge<br> **[Shruti]** Continue report write up and plan final meeting|
|19/06|Final meeting|June 19|||**[All]** Meet up and discuss project, finish writing up report and personal logs <br> **[Architects and Testers]** Check all functions are 80 lines or less, clean up code|

Deadlines for challenge section are not fixed, dependent on how quickly we can finish core and completion. 
