#include "mnblas.h"
#include "complexe.h"

float  mnblas_sasum(const int N, const float *X, const int incX)
{
    float out = 0.0;
    for (int i =0; i<N;i+=incX){
        if (X[i]<0)
        {
            out+=-X[i];
        }
        else
        {
            out+=X[i];
        }
    }
    return out;
}

double mnblas_dasum(const int N, const double *X, const int incX)
{
    double out = 0.0;
    for (int i =0; i<N;i+=incX){
        if (X[i]<0)
        {
            out+=-X[i];
        }
        else
        {
            out+=X[i];
        }
    }
    return out;
}

float  mnblas_scasum(const int N, const complexe_float_t *X, const int incX)
{
    float out = 0.0;
    for (int i =0; i<N;i+=incX)
    {
        if (X[i].real<0)
        {
            out+= -X[i].real;
        }
        else
        {
            out+= X[i].real;
        }
        if (X[i].imaginary<0)
        {
            out+= -X[i].imaginary;
        }
        else
        {
            out+= X[i].imaginary;
        }

        
    }
    return out;
}

double mnblas_dzasum(const int N, const complexe_double_t *X, const int incX)
{
    double out = 0.0;
    for (int i =0; i<N;i+=incX)
    {
        if (X[i].real<0)
        {
            out+= -X[i].real;
        }
        else
        {
            out+= X[i].real;
        }
        if (X[i].imaginary<0)
        {
            out+= -X[i].imaginary;
        }
        else
        {
            out+= X[i].imaginary;
        }

        
    }
    return out;
}