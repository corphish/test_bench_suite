#include "benchmark.h"
#include <stdio.h>

#define N 1024

void long_task_logn() {
	int i;
	for (i = N;i ; i /= 2);
}

void long_task_n() {
	int i = 0;
	for (;i < N; i++);
}

void long_task_nlogn() {
	int i = 0, j;
	for (;i < N; i++)
		for(j = N; j; j /= 2);
}

void long_task_nsquare() {
	int i = 0, j;
	for (;i < N; i++)
		for(j = 0;j < N;j++);
}

int main(int argc, char const *argv[])
{
	test_t test_logn = {
		.name = "Long task O(logn)",
		.function = long_task_logn,
	};

	test_t test_n = {
		.name = "Long task O(n)",
		.function = long_task_n,
	};

	test_t test_nlogn = {
		.name = "Long task O(nlogn)",
		.function = long_task_nlogn,
	};

	test_t test_nsquare = {
		.name = "Long task O(n^2)",
		.function = long_task_nsquare,
	};

	printf("Value of n - %d\n", N);
	run_benchmark(&test_logn);
	run_benchmark(&test_n);
	run_benchmark(&test_nlogn);
	run_benchmark(&test_nsquare);
	return 0;
}