#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "../lib/helper.h"
#include "benchmark_blas.h"

void bench_cblas_sscal(const int N, int printStyle) {
	const float alpha = randomAlphaf(); 
	float *X = randomVectorf(N) ;
	CALCTIME(cblas_sscal, N, alpha, X, 1);
	printBenchmark(N, N, N, calcTime, 4, printStyle);
}

void bench_cblas_dscal(const int N, int printStyle) {
	const double alpha = randomAlphad(); 
	double *X = randomVectord(N) ;
	CALCTIME(cblas_dscal, N, alpha, X, 1);
	printBenchmark(N, N, N, calcTime, 8, printStyle);
}

void bench_cblas_sdot(const int N, int printStyle) {
	float *X = randomVectorf(N);
	float *Y = randomVectorf(N);
	CALCTIME(cblas_sdot, N, X, 1, Y, 1);
	int operations = 2 * N;
	int count = 2 * N;
	printBenchmark(N, operations, count, calcTime, 4, printStyle);
}

void bench_cblas_ddot(const int N, int printStyle) {
	double *X = randomVectord(N);
	double *Y = randomVectord(N);
	CALCTIME(cblas_ddot, N, X, 1, Y, 1);
	int operations = 2 * N;
	int count = 2 * N;
	printBenchmark(N, operations, count, calcTime, 8, printStyle);
}

void bench_cblas_saxpy(const int N, int printStyle) {
	const float alpha = randomAlphaf(); 
	float *X = randomVectorf(N) ;
	float *Y = randomVectorf(N) ;
	CALCTIME(cblas_saxpy, N, alpha, X, 1, Y, 1);
	int operations = 2 * N;
	int count = 2 * N;
	printBenchmark(N, operations, count, calcTime, 4, printStyle);
}

void bench_cblas_daxpy(const int N, int printStyle) {
	const double alpha = randomAlphad(); 
	double *X = randomVectord(N) ;
	double *Y = randomVectord(N) ;
	CALCTIME(cblas_daxpy, N, alpha, X, 1, Y, 1);
	int operations = 2 * N;
	int count = 2 * N;
	printBenchmark(N, operations, count, calcTime, 8, printStyle);
}

void bench_cblas_sgemv(const int N, int printStyle) {
	const float alpha = randomAlphaf();
	const float beta = randomAlphaf();
	float *X = randomVectorf(N);
	float *Y = randomVectorf(N);
	float *A = randomMatrixf(N, N);
	CALCTIME(cblas_sgemv, CblasRowMajor, CblasNoTrans, N, N, alpha, A, N, X, 1, beta, Y, 1);
	int operations = 1ll * N * (3 + 2 * N);
	int count = 1ll * N * N + N + N;
	printBenchmark(N, operations, count, calcTime, 4, printStyle);
}

void bench_cblas_dgemv(const int N, int printStyle) {
	const double alpha = randomAlphad();
	const double beta = randomAlphad();
	double *X = randomVectord(N);
	double *Y = randomVectord(N);
	double *A = randomMatrixd(N, N);
	CALCTIME(cblas_dgemv, CblasRowMajor, CblasNoTrans, N, N, alpha, A, 1, X, 1, beta, Y, 1);
	int operations = 1ll * N * (3 + 2 * N);
	int count = 1ll * N * N + N + N;
	printBenchmark(N, operations, count, calcTime, 8, printStyle);
}

void bench_cblas_sgemm(const int N, int printStyle) {
	const float alpha = randomAlphaf();	
	const float beta = randomAlphaf();	
	float *A = randomMatrixf(N, N);
	float *B = randomMatrixf(N, N);
	float *C = randomMatrixf(N, N);
	CALCTIME(cblas_sgemm, CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, 
			N, alpha, A, N, B, N, beta, C, N);
	long operations = 1ll * 2 * N * N * N + 3 * N * N;
	long count = 3ll * N * N;
	printBenchmark(N, operations, count, calcTime, 4, printStyle);

}

void bench_cblas_dgemm(const int N, int printStyle) {
	const double alpha = randomAlphad();	
	const double beta = randomAlphad();	
	double *A = randomMatrixd(N, N);
	double *B = randomMatrixd(N, N);
	double *C = randomMatrixd(N, N);
	CALCTIME(cblas_dgemm, CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, 
			N, alpha, A, N, B, N, beta, C, N);
	long operations = 1ll * 2 * N * N * N + 3 * N * N;
	long count = 3ll * N * N;
	printBenchmark(N, operations, count, calcTime, 8, printStyle);

}
