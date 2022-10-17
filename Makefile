# Makefile SDL Synth 

TARGET 	= MySynth # final application
SRC		= $(wildcard */*.cpp)
INC 	= -IC:/SoftDev/SDL2/include -I./include # include dir header files
LIB 	= -LC:/SoftDev/SDL2/lib # precompiled libraries
CFLAGS 	= -Wall -w -Wl,-subsystem,console # compiler flags
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf # linker flags

all : $(SRC)
	g++ $(SRC) $(INC) $(LIB) $(CFLAGS) $(LDFLAGS) -o $(TARGET)