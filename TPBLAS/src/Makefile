LIB_DIR=../lib
INC_DIR=../include
OPTIM=-O2 -fopenmp

OPTIONS=-O2 -Wall -fPIC $(OPTIM) -I$(INC_DIR)

all: libmnblas.a libmnblasdyn.so

libmnblas.a: copy.o swap.o dot.o complexe.o gemv.o gemm.o axpy.o
	rm -f libmnblas.a $(LIB_DIR)/libmnblas.a
	ar -r libmnblas.a copy.o swap.o dot.o complexe.o gemv.o gemm.o axpy.o
	cp libmnblas.a $(LIB_DIR)

libmnblasdyn.so: copy.o swap.o dot.o complexe.o gemv.o gemm.o axpy.o
	rm -f libmnblasdyn.so $(LIB_DIR)/libmnblasdyn.so
	gcc -shared -o libmnblasdyn.so copy.o swap.o dot.o complexe.o gemv.o gemm.o axpy.o
	cp libmnblasdyn.so $(LIB_DIR)

complexe.o: BLAS1/complexe.c $(INC_DIR)/complexe.h
	gcc $(OPTIONS) -c BLAS1/complexe.c -o complexe.o

copy.o : BLAS1/copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS1/copy.c -o copy.o

swap.o : BLAS1/swap.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS1/swap.c -o swap.o 
	
axpy.o : BLAS1/axpy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS1/axpy.c -o axpy.o 

dot.o : BLAS1/dot.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS1/dot.c -o dot.o

gemv.o : BLAS2/gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS2/gemv.c -o gemv.o

gemm.o : BLAS3/gemm.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c BLAS3/gemm.c -o gemm.o


clean:
	rm -f *.o *.a *.so *~ $(INC_DIR)/*~ $(LIB_DIR)/libmnblasdyn.so $(LIB_DIR)/libmnblas.a ../lib/libmnblas.a ../lib/libmnblasdyn.so
