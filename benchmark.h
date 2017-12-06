#ifndef BENCHMARK_H
#define BENCHMARK_H

/**
 * This struct holds the test data
 * They are the name of the test and the function that the test performs
 */
typedef struct test {
	char* name;
	void (*function)(void); 
}test_t;


/**
 * This function runs the test
 */
void run_benchmark(test_t*);
#endif