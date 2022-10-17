# Makefile SDL Synth 

SRC = main.cpp audio.cpp render.cpp input.cpp # source files
TARGET = MySynth # final application
INCLUDE = C:\SoftDev\SDL\include # include dir header files
LIB = C:\SoftDev\SDL\lib # precompiled libraries
CFLAGS = -Wall -w -Wl,-subsystem,console # compiler flags
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf # linker flags

all : $(SRC)
	g++ $(SRC) -I$(INCLUDE) -L$(LIB) $(CFLAGS) $(LDFLAGS) -o $(TARGET)