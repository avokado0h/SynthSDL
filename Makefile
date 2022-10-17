# Makefile SDL Synth 

TARGET 		= MySynth # final application
SRC 		= src\main.cpp src\audio.cpp src\render.cpp src\input.cpp # source files
INCLUDE 	= C:\SoftDev\SDL\include # include dir header files
LIB 		= C:\SoftDev\SDL\lib # precompiled libraries
CFLAGS 		= -Wall -w -Wl,-subsystem,console # compiler flags
LDFLAGS 	= -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf # linker flags

all : $(SRC)
	g++ $(SRC) -I$(INCLUDE) -I.\include -L$(LIB) $(CFLAGS) $(LDFLAGS) -o $(TARGET)