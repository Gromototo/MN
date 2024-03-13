#include <stdio.h>
#include <assert.h>


#include "../src/BLAS3/gemm.c"

void test1(){

  const float A[6] = {1, 2, 5, 3, 4, 6};
  const float B[6] = {5, 6, 7, 8, 9, 10};

  float C[4] = {9, 10, 11, 12};

  const float alpha = 2;
  const float beta = 3;

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_sgemm( 0,  0,
                  0, M, N,
                 K,  alpha, &A,
                 0, &B, 0,
                 beta,  &C, 0);


  const float R[4] = {155, 174, 227, 256};
  for (int i = 0; i < 4; i++) {
    assert(C[i] == R[i]);
    //printf("%f ", C[i]);
  }
  return;
}


void main(){

  test1();
  return;
}
