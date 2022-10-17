# Makefile SynthSDL

# final application
TARGET = MySynth

# find .cpp files and compile
SRC = $(wildcard */*.cpp)

# include dir header files
INC = -IC:/SoftDev/SDL2/include -I./include 

# precompiled libraries
LIB = -LC:/SoftDev/SDL2/lib 

# compiler flags
CFLAGS = -Wall -g #-w -Wl,-subsystem,console 

# linker flags
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf 

all : $(SRC)
	g++ $(SRC) $(INC) $(LIB) $(CFLAGS) $(LDFLAGS) -o $(TARGET)