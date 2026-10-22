# Space-Out

A game built with [raylib](https://www.raylib.com/).

## Dependencies

A C++20 compiler, CMake 3.16+, Git, and the X11/OpenGL headers. On Debian/Ubuntu:

```sh
sudo apt install build-essential cmake git \
    libgl1-mesa-dev libx11-dev libxrandr-dev libxi-dev \
    libxcursor-dev libxinerama-dev libasound2-dev
```

raylib is fetched and built by CMake. Nothing is installed system-wide.

## Building

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

The first build compiles raylib and takes a few minutes.

## Running

```sh
./build/space-out
```

## Notes

Under WSL, Mesa defaults to software rendering. Run with `GALLIUM_DRIVER=d3d12`
to use the GPU; raylib prints the active renderer at startup.

Binaries require the glibc of the build machine or newer. Build on the oldest
distribution you intend to support.
