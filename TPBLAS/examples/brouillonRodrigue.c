
void test3(){

  

  const complexe_float_t A[6] = {{1.0f, 0.0f}, {2.0f, 0.0f}, {5.0f, 0.0f}, {3.0f, 0.0f}, {4.0f, 0.0f}, {6.0f, 0.0f}};
  const struct complexe_float_t B[6] = {{5.0, 0.0}, {6.0, 0.0}, {7.0, 0.0}, {8.0, 0.0}, {9.0,  0.0}, {10.0, 0.0}};

  const struct complexe_float_t C[4] = {{9, 0}, {10, 0}, {11, 0}, {12, 0}};

  const int alpha = 2;
  const int beta = 3;

  const int M = 2;
  const int K = 3;
  const int N = 2;

  mncblas_cgemm(0, 0, 0, M, N,K, alpha,  A,
                 0, B, 0,beta, C, 0);


  const struct complexe_float_t R[4] = {{155, 0}, {174, 0}, {227, 0}, {256, 0}};
  for (int i = 0; i < 4; i++) {
    printf("%lf %lf \n", C[i], R[i]);
    assert(C[i] == R[i]);
  }

  
  return;
}