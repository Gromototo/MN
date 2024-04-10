all: test_complexe4 test_complexe3 test_complexe2 test_complexe test_dot test_dot_omp test_dot_dyn test_copy test_copy_omp test_gemv test_gemv_omp test_swap test_gemm test_gemm_omp #test_axpy_omp #test_axpy 

INC_DIR=../include

LIB_DIR=../lib

LIBST= ../src/libmnblas.a
LIBDYN= ../src/libmnblasdyn.so

OPTIONS_COMPIL  =-Wall -O2 -fPIC -I$(INC_DIR)

OPTIONS_LINK_STATIC  = -fopenmp -L$(LIB_DIR) $(LIBST) -lm
OPTIONS_LINK_DYN     = -fopenmp -L$(LIB_DIR) $(LIBDYN) -lm

test_dot: test_dot.o flop.o $(LIBST)
	gcc -o test_dot test_dot.o flop.o $(OPTIONS_LINK_STATIC)

test_dot.o: test_dot.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_dot.c

flop.o: flop.c flop.h
	gcc $(OPTIONS_COMPIL) -c flop.c

test_dot_dyn: test_dot.o flop.o
	gcc -o test_dot_dyn flop.o test_dot.o $(OPTIONS_LINK_DYN)


test_complexe.o: test_complexe.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_complexe.c

test_complexe: test_complexe.o flop.o
	gcc -o test_complexe test_complexe.o flop.o $(OPTIONS_LINK_STATIC) 

test_complexe2.o: test_complexe2.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe2.c

test_complexe2: test_complexe2.o flop.o
	gcc -o test_complexe2 test_complexe2.o flop.o $(OPTIONS_LINK_STATIC)


test_complexe3.o: test_complexe3.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe3.c

test_complexe3: test_complexe3.o flop.o
	gcc -o test_complexe3 test_complexe3.o flop.o $(OPTIONS_LINK_STATIC)

test_complexe4.o: test_complexe4.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe4.c

test_complexe4: test_complexe4.o flop.o
	gcc -o test_complexe4 test_complexe4.o flop.o $(OPTIONS_LINK_STATIC)


#CUSTOM TESTS

test_copy: test_copy.o $(LIBST)
	gcc -o test_copy test_copy.o  $(OPTIONS_LINK_STATIC)

test_copy.o: test_copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_copy.c

test_copy_omp: test_copy_omp.o $(LIBST)
	gcc -o test_copy_omp test_copy_omp.o  $(OPTIONS_LINK_STATIC)

test_copy_omp.o: test_copy_omp.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_copy_omp.c

test_gemv: test_gemv.o $(LIBST)
	gcc -o test_gemv test_gemv.o  $(OPTIONS_LINK_STATIC)


test_gemv.o: test_gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_gemv.c


test_gemv_omp: test_gemv_omp.o $(LIBST)
	gcc -o test_gemv_omp test_gemv_omp.o  $(OPTIONS_LINK_STATIC)


test_gemv_omp.o: test_gemv_omp.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_gemv_omp.c


test_swap: test_swap.o $(LIBST)
	gcc -o test_swap test_swap.o  $(OPTIONS_LINK_STATIC)

test_swap.o: test_swap.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_swap.c

test_axpy: test_axpy.o $(LIBST)
	gcc -o test_axpy test_axpy.o  $(OPTIONS_LINK_STATIC)

test_axpy.o: test_axpy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_axpy.c

test_axpy_omp: test_axpy_omp.o $(LIBST)
	gcc -o test_axpy_omp test_axpy_omp.o  $(OPTIONS_LINK_STATIC)

test_axpy_omp.o: test_axpy_omp.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_axpy_omp.c


test_gemm: test_gemm.o $(LIBST)
	gcc -o test_gemm test_gemm.o  $(OPTIONS_LINK_STATIC)

test_gemm.o: test_gemm.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_gemm.c

test_gemm_omp: test_gemm_omp.o $(LIBST)
	gcc -o test_gemm_omp test_gemm_omp.o  $(OPTIONS_LINK_STATIC)


test_gemm_omp.o: test_gemm_omp.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_gemm_omp.c

clean:
	rm -f *.o test_dot test_dot_dyn test_complexe test_complexe2 test_complexe3 test_complexe4 test_swap test_gemv test_gemv_omp test_copy test_gemm test_gemmv *~