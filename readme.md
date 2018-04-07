# cpp examples

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
pacman -S make
pacman -S cmake
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

```bash
cmake -G"MSYS Makefiles" ..
make VERBOSE=1
```

## gtkmm example

On ubuntu install the required development dependencies

```bash
    sudo apt install libgtkmm-3.0-dev
```

The one liner compilation command could be

```console
ibqn@pLs> g++ gtkmm-hello.cpp -o gtkmm-hello $(pkg-config gtkmm-3.0 --cflags --libs)
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

Do the same at the build_release dir but with `-DCMAKE_BUILD_TYPE=Release`
