#include "mnblas.h"
#include <stdio.h>

void test00(){
    float A[9] = {1.0,0.0,0.0,2.0,1.0,0.0,4.0,3.0,2.0};
    float B[9] = {1.0,2.0,1.0,0.0,3.0,2.0,0.0,0.0,1.0};

    float x[3] = {3.0,2.0,2.0};
    mncblas_strmv(MNCblasLower, MNCblasNoTrans,MNCblasNonUnit,3,A,1,x,1);

    for (int i = 0; i<3; i++){
        printf("%f\n",x[i]);
    }

}

int main(){
    test00();

}