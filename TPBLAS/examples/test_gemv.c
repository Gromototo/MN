#include "../src/BLAS2/gemv.c"
#include <stdio.h>

void test01(){
   float Mat_A[9] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0}; //3*3
    float Vect_X[3] = {4.0,8.0,7.0};
    float Vect_Y[3] = {3.0,5.0,9.0};
    float alpha= 2.0;
    float beta = 3.0;
    mncblas_sgemv(3,101,3,3, alpha,Mat_A, 0, Vect_X, 1,beta, Vect_Y, 1);
    for (int i = 0; i<3; i++){
        printf("%f\n", Vect_Y[i]);
    }
}

int main(){
    test01();
    return 1;
}