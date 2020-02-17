// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// Chinmaya Joshi
// csj744
// Slip days used: 0
// Spring 2020
// Include the contents of this file at the top of every file that you submit, replacing the fields within <>.  Do not keep the <>.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
	for(uint32_t i=0;i<a_rows;i++){
		for(uint32_t j=0;j<b_cols;j++){
			c[(i*b_cols)+j] = 0;
			for(uint32_t k=0;k<a_cols;k++){
				c[(i*b_cols)+j] += a[(i*a_cols)+k] * b[(k*b_cols)+j];
			}
		}
	}
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
	double** c = (double**)malloc(a_rows*sizeof(double*));
	for(uint32_t i=0;i<a_rows;i++){
		c[i]=(double*)calloc(b_cols,sizeof(double));
		for(uint32_t j=0;j<b_cols;j++){
			for(uint32_t k=0;k<a_cols;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
    return c;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols) {
	double** c = (double**)malloc(a_cols*sizeof(double*));
	for(uint32_t i=0;i<a_cols;i++){
		c[i]=(double*)malloc(a_rows*sizeof(double));
		for(uint32_t j=0;j<a_rows;j++){
			c[i][j]=a[j][i];
		}
	}
    return c;
}
