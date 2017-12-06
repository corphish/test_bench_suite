# Test bench suite
This lets you measure the CPU time taken to execute a function in a generic way. The time returned is in microseconds. Thanks to @cswl for showing me the way of measuring CPU time.

## Compile
This suite is available as a shared library. You can compile the library using `make lib`. This will generate `libbenchmark.so`. You can then link against this library with your own executable.

## How to use this lib?
* In your executable source, include the library header file by `#include "benchmark.h"`.
* If you haven't built the lib already, build using `make lib` from terminal.
* Define your (long running?) function, so that it can be invoked from your executable source.
* If the function you want to test, has parameters, wrap it up in a void function with no parameters. In that function, call the required long running function and supply appropriate parameters.
* Then create `test_t` struct, as follows: 
```C
test_t sample_test {
    .name = "Name of the test",
    .function = long_running_function_wrapper,
};
```
* And then run the test by: `run_benchmark(&sample_test);`


## Sample Implementation
Check the [test.c](https://github.com/corphish/test_bench_suite/blob/master/test.c) to get a brief idea on how to use this.

## License
[WTFPL](http://www.wtfpl.net/)