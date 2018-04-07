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

```bash
cd cmake-hello
mkdir build
cd build
cmake ..
make
./hello
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
