# Raylib - Basic Project

This is a little template that gives you small start to begin with [raylib](https://github.com/raysan5/raylib). Feel free to contribute :smiley:.

This was tested on Linux and Windows 10, using [CLion](https://www.jetbrains.com/clion/) and [VScode](https://code.visualstudio.com/).

## Instructions

### Linux | Windows (Using MINGW)

- [Using a script](#Using-a-script)
- [Compiled from source](#Compiled-from-source)
- [Using precompiled files](#Using-precompiled-files)

#### Using a script

If you have python installed on your computer, make the necessary configurations on the `setup.py` file and run the script.

#### Compiled from source

If you compiled raylib from source, copy the `raylib.h` file (`raylib/src/raylib.h`) to the `include` folder of this project. After that, just copy the compiled file `libraylib.a` (`raylib/libraylib.a` on linux or `raylib/src/libraylib.a` on Windows) to the `lib` folder of this project.

#### Using precompiled files

If you want, you can [download](https://github.com/raysan5/raylib/releases/latest) the binaries correspondent to your platform, extract them and move the `include` and `lib` folders to the ones with the correspondent names in this project.
