INCLUDE = -I PLACEHOLDER
LIBS = -L PLACEHOLDER
robot.exe: robot.o
	g++ $(LIBS) -o robot robot.o -lsfml-window  -lsfml-graphics -lsfml-system -lsfml-network
robot.o: robot.cpp
	g++  -c $(INCLUDE) robot.cpp

