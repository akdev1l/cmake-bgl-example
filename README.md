# Boost Graph CMake Example

This project is intended to showcase how to integrate the Boost Graph Library onto a new CMake project.
The program implemented here just generates a rather bland graphviz graph.

If you want to see the graph you can use the `xdot` utility.

## How to build

You can build this project by doing:

```bash
$ mkdir build/
$ cd build/
$ cmake ../
$ make
```

The resulting program will be located inside `build/bin`.

## Dependencies

- CMake 3.11 or higher
- Boost development packages must be installed (obviously)
- The project needs a C++17 compliant compiler.
