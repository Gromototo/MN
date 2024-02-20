#include "../../include/mnblas.h"
#include "../../include/complexe.h"
#include <stdlib.h>

CBLAS_INDEX mnblas_isamax(const int N, const float  *X, const int incX)
{
    CBLAS_INDEX out = 0;
    float max = (float) abs((int) X[0]);
    for (int i = 1; i<N; i++)
    {
        if (max < (float) abs((int) X[i]))
        {
            max = (float) abs((int) X[i]);
            out = i;
        }
    }
    return out;
}

CBLAS_INDEX mnblas_idamax(const int N, const double *X, const int incX)
{
    CBLAS_INDEX out = 0;
    double max = (double) abs((int) X[0]);
    for (int i = 1; i<N; i++)
    {
        if (max < (double) abs((int) X[i]))
        {
            max = (double) abs((int) X[i]);
            out = i;
        }
    }
    return out;
}


CBLAS_INDEX mnblas_icamax(const int N, const complexe_float_t  *X, const int incX)
{
    CBLAS_INDEX out = 0;
    float max = module_float(X[0]);

    for (int i = 1; i<N; i+=incX)
    {
        if (max < module_float(X[i]))
        {
            max = module_float(X[i]);
            out = i;
        }
    }
    return out;
}

CBLAS_INDEX mnblas_izamax(const int N, const complexe_double_t  *X, const int incX)
{
    CBLAS_INDEX out = 0;
    float max = module_double(X[0]);

    for (int i = 1; i<N; i+=incX)
    {
        if (max < module_double(X[i]))
        {
            max = module_double(X[i]);
            out = i;
        }
    }
    return out;
}