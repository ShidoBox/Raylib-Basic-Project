# Raylib - Basic Project
This is a little template that gives you small start to begin with [raylib](https://github.com/raysan5/raylib). Feel free to contribuite :smiley:.

This was testes on Linux and Windows 10, using [CLion](https://www.jetbrains.com/clion/) and [VScode](https://code.visualstudio.com/).

## Instructions

### Linux | Windows (Using MINGW)

#### Compiled from source
If you compiled from source, copy the `raylib.h` file (`raylib/src/raylib.h`) to the `src` folder of this project. After that, just copy the compiled file `libraylib.a` (`raylib/libraylib.a` on linux or `raylib/src/libraylib.a` on Windows) to the `lib` folder of this project.

#### Using precompiled files
Just [download](https://github.com/raysan5/raylib/releases) the binaries correspondent to your platform, extract them and move the `include` and `lib` folders to the ones with the correspondent names in this project.