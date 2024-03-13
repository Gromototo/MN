#include "../../include/complexe.h"

#include <math.h>

complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

complexe_float_t sub_complexe_float(const complexe_float_t c1, const complexe_float_t c2){

    complexe_float_t r;
    r.real = c1.real-c2.real;
    r.imaginary = c1.imaginary-c2.imaginary;

    return r;
}

complexe_double_t sub_complexe_double(const complexe_double_t c1, const complexe_double_t c2){
    complexe_double_t r;
    r.real = c1.real-c2.real;
    r.imaginary = c1.imaginary-c2.imaginary;

    return r;
}


complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real * c2.real - c1.imaginary*c2.imaginary ;
  r.imaginary = c1.real*c2.imaginary + c1.imaginary*c2.real ;
  
  return r ;
}

complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
  {
  complexe_double_t r ;

  r.real = c1.real * c2.real - c1.imaginary*c2.imaginary ;
  r.imaginary = c1.real*c2.imaginary + c1.imaginary*c2.real ;
  
  return r ;
}
  

complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = (c1.real*c2.real + c1.imaginary*c2.imaginary)/(c2.real*c2.real + c1.imaginary*c1.imaginary);
  r.imaginary = (c2.real*c1.imaginary - c1.real*c2.imaginary)/(c2.real*c2.real + c1.imaginary*c1.imaginary);
  
  return r ;
}

complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = (c1.real*c2.real + c1.imaginary*c2.imaginary)/(c2.real*c2.real + c1.imaginary*c1.imaginary);
  r.imaginary = (c2.real*c1.imaginary - c1.real*c2.imaginary)/(c2.real*c2.real + c1.imaginary*c1.imaginary);
  
  return r ;
}

complexe_float_t conjugate_complexe_float (const complexe_float_t c1){
    complexe_float_t r;
    r.real = c1.real;
    r.imaginary = -c1.imaginary;
    return r;
}

complexe_double_t conjugate_complexe_double (const complexe_double_t c1){
    complexe_double_t r;
    r.real = c1.real;
    r.imaginary = -c1.imaginary;
    return r;
}

float module_float (const complexe_float_t c1){

    return (float) sqrt((double) c1.real*c1.real + c1.imaginary*c1.imaginary);

}

double module_double (const complexe_double_t c1)
{
        return sqrt(c1.real*c1.real + c1.imaginary*c1.imaginary);

}