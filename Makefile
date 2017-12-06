all: lib test

lib: benchmark.c benchmark.h
	@gcc -c -fPIC benchmark.c
	@gcc -shared -o libbenchmark.so benchmark.o

test: test.c
	@gcc -o test test.c -L. -lbenchmark

clean:
	@rm -rf *.so *.o test