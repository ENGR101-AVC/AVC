# AVC
## Installation (for Windows)
### Installing Geany
Go to https://geany.org/download/releases/ and click "geany-1.36_setup.exe" in the Windows row. This will download geany onto your machine. Then go to https://sourceforge.net/projects/tdm-gcc/ and click the download button to download the TDM_GCC Compiler installer. Open up the geany setup and click "I Agree", choose the default components, choose a place of your liking to download it, and install the software and click finish. Open up the TDM-GCC setup, click create and select the "MinGW-w64 (32-bit and 64-bit)" edition. Click next for all options unless you would like to make your own modifications then click install and finish. Geany should be fully functional on your Windows machine now.
### Installing SFML
First you must install the SFML library from this site: https://www.sfml-dev.org/download/sfml/2.5.1/, if you are running on geany and minGW can sure you download the minGW versions of the library and it's corresponding version (32 bit or 64 bit).

Afterwards, create a folder in your (C:) drive called SFML and move the downloaded zip file into this folder and unzip it.

Now download the AVC_master branch, unzip the folder anywhere and copy out the AVC_Robot_Windows folder and save it anywhere you like.

Open the C:SFML folder and open the folder "include" and copy the file path for it. Then open the makefile file in the AVC_robot folder with geany and paste the file path into the line that starts with "INCLUDE" just after the "-I" and delete the place holder path. Open C:SFML again and open the file "lib" and copy the file path. Paste the lib file path in the line that starts with "LIBS" after "-L" and delete the place holder path.  Repeat this instruction but instead use the makefile file in the AVC_server folder.

Finally, open server3.cpp and robot.cpp in geany and go to "Set Build Commands" which should be located in the "Build" section of the nav bar. In the "Independant commands" in the 1st row, 2nd column change "make" to "mingw32-make".

Instead of using compile, build and run press shift+F9 to make the code. Do this make command for both server3.cpp and robot.cpp and they should  both successfully compile (robot.cpp will give warnings before successfully compiling but that's okay). Then press F5 to run the two .cpp files. Make sure you run server3.cpp first before running robot.cpp or else the program will not work.

If you try and compile the two .cpp files but are unsuccessful try and delete the server3.o file from the AVC_server folder and the robot.o from the AVC_robot folder.

### Downloading Our Code
Downloading code is done by cloning our github repository. In Github Desktop, we can do this by going to Current Repository > Add > URL and paste in https://github.com/ENGR101-AVC/AVC.git

### Changing the Map
You can change the map by editing the config.txt file in server folder. By default it is set to core.txt. 

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
