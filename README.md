# SynthSDL

## Dependencies

MinGW 
- compiler and make utilities [download here](https://github.com/niXman/mingw-builds-binaries/releases)
- tested with `i686-12.2.0-release-posix-dwarf-rt_v10-rev0`

SDL2 for MinGW
- SDL2 MinGW binaries and libs [download here](https://github.com/libsdl-org/SDL/releases)
- SDL2_ttf for MinGW [download here](https://github.com/libsdl-org/SDL_ttf/releases)
- tested with `SDL2-devel-2.24.1-mingw.zip` and `SDL2_ttf-devel-2.20.1-mingw.zip`

## HowTo
- add `mingw32\bin` and `SDL\bin` to windows PATH
- compile with `mingw32-make`