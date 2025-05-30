# Alpha Game Engine

## Build

### CMake

```Bash
mkdir temp
cd temp
cmake ..
make
../bin/alpha
```

### Running tests

Find the latest [`Catch2`](https://github.com/catchorg/Catch2/releases) release, and download both amalgamation files (`.hpp` and `.cpp`) and place them in `/alpha/tests/`

```Bash
cd tests
wget {catch_amalgamation.cpp} .
wget {catch_amalgamation.hpp} .
```

Then to run the tests, build with `-DBUILD_TEST=ON`, then run `/alpha/bin/runTests`

```Bash
cd temp
cmake .. -DBUILD_TESTS=ON
make
../bin/runTests
```
