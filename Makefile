#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = MySynth

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -IC:\SoftDev\SDL\include -LC:\SoftDev\SDL\lib -w -Wl,-subsystem,console -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -o $(OBJ_NAME)