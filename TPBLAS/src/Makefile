LIB_DIR=../lib
INC_DIR=../include
OPTIM=-O2 -fopenmp

BLAS_DIR = BLAS1

OPTIONS=-O2 -Wall -fPIC $(OPTIM) -I$(INC_DIR)

all: libmnblas.a libmnblasdyn.so

libmnblas.a: copy.o swap.o dot.o complexe.o
	rm -f libmnblas.a $(LIB_DIR)/libmnblas.a
	ar -r libmnblas.a copy.o swap.o dot.o complexe.o
	cp libmnblas.a $(LIB_DIR)

libmnblasdyn.so: copy.o swap.o dot.o complexe.o
	rm -f libmnblasdyn.so $(LIB_DIR)/libmnblasdyn.so
	gcc -shared -o libmnblasdyn.so copy.o swap.o dot.o complexe.o
	cp libmnblasdyn.so $(LIB_DIR)

complexe.o: $(BLAS_DIR)/complexe.c $(INC_DIR)/complexe.h
	gcc $(OPTIONS) -c $(BLAS_DIR)/complexe.c -o complexe.o

copy.o : $(BLAS_DIR)/copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c $(BLAS_DIR)/copy.c -o copy.o

swap.o : $(BLAS_DIR)/swap.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c $(BLAS_DIR)/swap.c -o swap.o 
	
axpy.o : $(BLAS_DIR)/axpy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c $(BLAS_DIR)/axpy.c -o axpy.o 

dot.o : $(BLAS_DIR)/dot.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c $(BLAS_DIR)/dot.c -o dot.o




clean:
	rm -f *.o *.a *.so *~ $(INC_DIR)/*~ $(LIB_DIR)/libmnblasdyn.so $(LIB_DIR)/libmnblas.a ../lib/libmnblas.a ../lib/libmnblasdyn.so
