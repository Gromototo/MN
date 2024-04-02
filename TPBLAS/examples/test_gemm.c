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
                 K,  alpha, A,
                 0, B, 0,
                 beta,  C, 0);


  const float R[4] = {155, 174, 227, 256};
  for (int i = 0; i < 4; i++) {
    assert(C[i] == R[i]);
    //printf("%f ", C[i]);
  }

  
  return;
}

void test2(){

  const double A[6] = {1, 2, 5, 3, 4, 6};
  const double B[6] = {5, 6, 7, 8, 9, 10};

  double C[4] = {9, 10, 11, 12};

  const double alpha = 2;
  const double beta = 3;

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_dgemm( 0,  0,
                  0, M, N,
                 K,  alpha, A,
                 0, B, 0,
                 beta,  C, 0);


  const double R[4] = {155, 174, 227, 256};
  for (int i = 0; i < 4; i++) {
    printf("%lf %lf \n", C[i], R[i]);
    assert(C[i] == R[i]);
  }

  
  return;
}




void test3(){

  

  const complexe_float_t A[6] = {{1.0f, 0.0f}, {2.0f, 0.0f}, {5.0f, 0.0f}, {3.0f, 0.0f}, {4.0f, 0.0f}, {6.0f, 0.0f}};
  const complexe_float_t B[6] = {{5.0, 0.0}, {6.0, 0.0}, {7.0, 0.0}, {8.0, 0.0}, {9.0,  0.0}, {10.0, 0.0}};

  complexe_float_t C[4] = {{9.0, 0.0}, {10.0, 0.0}, {11.0, 0.0}, {12.0, 0.0}};

  const complexe_float_t alpha = {2.0f, 0.0f};
  const complexe_float_t beta = {3.0f, 0.0f};

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_cgemm(0, 0, 0, M, N,K, &alpha,  A,
                 0, B, 0,&beta, C, 0);


  const complexe_float_t R[4] = {{155.0, 0.0}, {174.0, 0}, {227.0, 0.0}, {256.0, 0.0}};
  for (int i = 0; i < 4; i++) {
    printf("%f %f %f %f \n",C[i].real, C[i].imaginary, R[i].real, R[i].imaginary);
    assert(C[i].real == R[i].real);
    assert(C[i].imaginary == R[i].imaginary);
  }
  
  return;
}

int main(){

  test1();
  test2();
  test3();
  printf("Gemm tests passed\n");
  return 1;
}
