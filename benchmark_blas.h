#ifndef BCBLASH_H
#define BCBLASH_H
#include "cblas.h"

void bench_cblas_sscal(const int N, int printStyle);
void bench_cblas_dscal(const int N, int printStyle);
void bench_cblas_sdot(const int N, int printStyle);
void bench_cblas_saxpy(const int N, int printStyle);
void bench_cblas_sgemv(const int N, int printStyle);

#endif
