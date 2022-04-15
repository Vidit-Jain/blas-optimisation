#include "benchmark_blas.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	if (argc != 6) {
		printf("Incorrect number of arguments passed\n");
		return 0;
	}
	char* function = argv[1];
	int style = atoi(argv[2]);
	long startingN = atoi(argv[3]);
	int factor = atoi(argv[4]);
	int iterations = atoi(argv[5]);
	srand((unsigned)time(NULL));

	if (style == 1)
		printf("Benchmarking %s\n", function);

	void (*f)(int, int);
	if (!strcmp("sscal", function)) f = &bench_cblas_sscal;
	else if (!strcmp("sdot", function)) f = &bench_cblas_sdot;
	else f = &bench_cblas_sscal;

	long N = startingN;
	for (int i = 0; i < iterations; i++, N *= factor) {
		f(N, style);
	}	
}
