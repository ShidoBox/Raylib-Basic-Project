# Raylib - Basic Project

This is a little template that gives you small start to begin with [raylib](https://github.com/raysan5/raylib). Instead of the traditional example of opening a window, this example aims to create a more dynamic and interesting one. It was a rotating cube, using different modules of raylib, such as raygui, rlgl and raymath.

![Final Goal](./preview.gif)

This was tested on Linux and Windows 10, using [CLion](https://www.jetbrains.com/clion/) and [VScode](https://code.visualstudio.com/). Feel free to contribute :smiley:.

## Instructions

### Linux | Windows (Using MINGW)

- [Using a script](#Using-a-script)
- [Compiled from source](#Compiled-from-source)
- [Using precompiled files](#Using-precompiled-files)

#### Using a script

If you have python installed on your computer, make the necessary configurations on the `setup.py` file and run the script.

#### Compiled from source

If you compiled raylib from source, copy the `raylib.h`,`raymath.h`and `rlgl.h` files located at (`raylib/src/`) to the `include` folder of this project. You will also need the `raygui.h` file, there is a copy at `raylib/examples/shapes`, but is recommended that you use the version of the [official repo](https://github.com/raysan5/raygui). After that, just copy the compiled file `libraylib.a` (`raylib/libraylib.a` on linux or `raylib/src/libraylib.a` on Windows) to the `lib` folder of this project.

#### Using precompiled files

If you want, you can [download](https://github.com/raysan5/raylib/releases/latest) the binaries correspondent to your platform, extract them and move the `include` and `lib` folders to the ones with the correspondent names in this project. After that, put necessary dependencies **for this project** ([raygui](https://github.com/raysan5/raygui/blob/master/src/raygui.h), [rlgl](https://github.com/raysan5/raylib/blob/master/src/rlgl.h) e [raymath](https://github.com/raysan5/raylib/blob/master/src/raymath.h)) in the `include` folder.
