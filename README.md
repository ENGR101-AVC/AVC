# AVC
## Installation
*For any version make sure Geany is installed and can compile, build and run programs*
### Installing SFML
#### Mac 
Install Homebrew by typing this into the terminal.
>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

Once Homebrew is installed, paste this into terminal to install SFML:
>brew install sfml 

Open Geany and under build commands paste these flags after the pre-existing flags. 
>-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network 
### Downloading Our Code
Downloading code is done by cloning our github repository. In Github Desktop, we can do this by going to Current Repository > Add > URL and paste in https://github.com/ENGR101-AVC/AVC.git

### Compile Build and Run
Our make file does all of these steps automatically by executing make (MAC) or mingw-make(Windows).
To run programs, first you have to compile, build and then run (F8, F9 and then F5).
To make the robot work, you have to first compile, build and run the server3.cpp file. Then you have to compile, build and run the robot.cpp file. 

## Plan
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
