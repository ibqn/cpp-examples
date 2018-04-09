# Various C++ examples

## waf build system

```bash
cd waf-hello
./waf configure build
```

## cmake build system

On ubuntu install the required development dependencies

```bash
sudo apt install cmake
```

On Windows 10 we set everything up with MSYS2.
To install the one targeting x86_64:

```bash
pacman -S mingw-w64-x86_64-gcc
```

Install `make` and `cmake`

```bash
pacman -S mingw-w64-x86_64-make
pacman -S mingw-w64-x86_64-cmake
pacman -S make cmake
```

Might not be needed, but th ability to debug things cannot be bad

```bash
pacman -S mingw-w64-x86_64-gdb # ability to debug is always useful
```

To build the project in the `build` directory do the following

```bash
cd cmake-hello
mkdir build
cd build
```

On GNU/Linux systems we run `cmake ../` followed by `make`

```bash
cmake ..
make
./hello
```

The above commands were also working for me on Windows 10.
Or alternatively

```bash
cmake -G"MSYS Makefiles" ..
make VERBOSE=1
```

## gtkmm example

On ubuntu install the required development dependencies

```bash
sudo apt install libgtkmm-3.0-dev
```

On Windows 10 install additional dependencies for MSYS2

```bash
pacman -S mingw-w64-x86_64-gtkmm3
pacman -S mingw-w64-x86_64-pkg-config
```

The one liner compilation command could be

$ g++ gtkmm-hello.cpp -o gtkmm-hello $(pkg-config gtkmm-3.0 --cflags --libs)
```

```bash
cd gtkmm-hello
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ../
```

A bunch of Makefiles will be created by cmake. Now run make

```bash
make
./scr/gtkmm-hello
```

Do the same at the build_release dir but with `-DCMAKE_BUILD_TYPE=Release`.

Here, is the list of shared libraries on Windows 10:
```console
$ ldd ./src/gtkmm-hello.exe | grep  '/mingw64/'
        libglibmm-2.4-1.dll => /mingw64/bin/libglibmm-2.4-1.dll (0x664c0000)
        libgtkmm-3.0-1.dll => /mingw64/bin/libgtkmm-3.0-1.dll (0x63e40000)
        libstdc++-6.dll => /mingw64/bin/libstdc++-6.dll (0x6fc40000)
        libgcc_s_seh-1.dll => /mingw64/bin/libgcc_s_seh-1.dll (0x61440000)
        libwinpthread-1.dll => /mingw64/bin/libwinpthread-1.dll (0x64940000)
        libgmodule-2.0-0.dll => /mingw64/bin/libgmodule-2.0-0.dll (0x6dd00000)
        libgobject-2.0-0.dll => /mingw64/bin/libgobject-2.0-0.dll (0x63a40000)
        libglib-2.0-0.dll => /mingw64/bin/libglib-2.0-0.dll (0x685c0000)
        libsigc-2.0-0.dll => /mingw64/bin/libsigc-2.0-0.dll (0x6aa00000)
        libgdkmm-3.0-1.dll => /mingw64/bin/libgdkmm-3.0-1.dll (0x688c0000)
        libatkmm-1.6-1.dll => /mingw64/bin/libatkmm-1.6-1.dll (0x6e980000)
        libcairomm-1.0-1.dll => /mingw64/bin/libcairomm-1.0-1.dll (0x62140000)
        libgdk-3-0.dll => /mingw64/bin/libgdk-3-0.dll (0x70ec0000)
        libgiomm-2.4-1.dll => /mingw64/bin/libgiomm-2.4-1.dll (0x6b780000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libpangomm-1.4-1.dll => /mingw64/bin/libpangomm-1.4-1.dll (0x6eac0000)
        libffi-6.dll => /mingw64/bin/libffi-6.dll (0x6b740000)
        libgdk_pixbuf-2.0-0.dll => /mingw64/bin/libgdk_pixbuf-2.0-0.dll (0x65340000)
        libatk-1.0-0.dll => /mingw64/bin/libatk-1.0-0.dll (0x62940000)
        libcairo-2.dll => /mingw64/bin/libcairo-2.dll (0x68dc0000)
        libgio-2.0-0.dll => /mingw64/bin/libgio-2.0-0.dll (0x6d580000)
        libcairo-gobject-2.dll => /mingw64/bin/libcairo-gobject-2.dll (0x6cf40000)
        libepoxy-0.dll => /mingw64/bin/libepoxy-0.dll (0x6df00000)
        libintl-8.dll => /mingw64/bin/libintl-8.dll (0x61cc0000)
        libpangocairo-1.0-0.dll => /mingw64/bin/libpangocairo-1.0-0.dll (0x6d4c0000)
        libpango-1.0-0.dll => /mingw64/bin/libpango-1.0-0.dll (0x65580000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libpcre-1.dll => /mingw64/bin/libpcre-1.dll (0x69140000)
        libfontconfig-1.dll => /mingw64/bin/libfontconfig-1.dll (0x64f80000)
        libfreetype-6.dll => /mingw64/bin/libfreetype-6.dll (0x693c0000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libpng16-16.dll => /mingw64/bin/libpng16-16.dll (0x68b40000)
        zlib1.dll => /mingw64/bin/zlib1.dll (0x62e80000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libiconv-2.dll => /mingw64/bin/libiconv-2.dll (0x66000000)
        libpangoft2-1.0-0.dll => /mingw64/bin/libpangoft2-1.0-0.dll (0x6d700000)
        libpangowin32-1.0-0.dll => /mingw64/bin/libpangowin32-1.0-0.dll (0x6b280000)
        libexpat-1.dll => /mingw64/bin/libexpat-1.dll (0x68f40000)
        libbz2-1.dll => /mingw64/bin/libbz2-1.dll (0x626c0000)
        libharfbuzz-0.dll => /mingw64/bin/libharfbuzz-0.dll (0x61600000)
        libgraphite2.dll => /mingw64/bin/libgraphite2.dll (0x70540000)
        libgtk-3-0.dll => /mingw64/bin/libgtk-3-0.dll (0x2d50000)
        libpixman-1-0.dll => /mingw64/bin/libpixman-1-0.dll (0x33c0000)
```

Useful links:

[GTKmm on MSWindows](https://wiki.gnome.org/Projects/gtkmm/MSWindows)

[GTKmm using CMake](https://wiki.gnome.org/Projects/gtkmm/UsingCMake)

[Development on Windows](https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2)

[GTK+ for Windows](https://www.gtk.org/download/windows.php)
