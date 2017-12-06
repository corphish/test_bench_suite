#include <stdio.h>
#include <time.h>

#include "benchmark.h"

void run_benchmark(test_t* test) {
	clock_t start, end;

	printf("Running %s\n", test->name);

	start = clock();

	test->function();

	end = clock();

	printf("Took %f microseconds.\n", (double)(1e6)*(end - start)/CLOCKS_PER_SEC);
}