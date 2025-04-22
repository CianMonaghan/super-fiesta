#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

/**
 * Clones vector
 * @param vector vector to be cloned
 * @param size size of vector
 * @return the copied vector
 */
int* vecClone(int* vector, int size){
    int* clone = (int*)malloc(size*sizeof(int));
    memcpy(clone, vector, size * sizeof(int));
    return clone;
}

/**
 * Clones matrix
 * @param matrix matrix to be cloned
 * @param rows number of rows
 * @param cols number of columns
 * @return the copied matrix
 */
int** matClone(int** matrix, int rows, int cols){
    int **clone = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        clone[i] = (int*)malloc(cols * sizeof(int));
        memcpy(clone[i], matrix[i], cols * sizeof(int));
    }
    return clone;
}

/**
 * Compares two same size vectors
 * @param vec1 first vector
 * @param vec2 second vector
 * @param size size of both vectors
 * @return the bigger vector if they differ, vec1 if they are the same
 */
int* vecCompare(int* vec1, int* vec2, int size){
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<size; i++){
        sum1 = sum1 + ((vec1[i])^2);
    }
    for(int i=0; i<size; i++){
        sum2 = sum2 + ((vec2[i])^2);
    }
    if(vec1 >= vec2){
        return vec1;
    } else {
        return vec2;
    }
}

/**
 * Subtract two same size vectors
 * @param vec1 first vector 
 * @param vec2 second vector
 * @param vecOutput output vector (is it bad form to do this? idk)
 * @param size size of both vectors
 */
void vecAdd(int* vec1, int* vec2, int* vecOutput, int size){
    for(int i=0; i<size; i++){
        vecOutput[i] = vec1[i]+vec2[i];
    }
}

/**
 * Adds two same size vectors
 * @param vec1 first vector
 * @param vec2 second vector
 * @param vecOutput output vector (is it bad form to do this? idk)
 * @param size size of both vectors
 */
void vecSub(int* vec1, int* vec2, int* vecOutput, int size){
    for(int i=0; i<size; i++){
        vecOutput[i] = vec1[i]-vec2[i];
    }
}

/**
 * Adds two same size matrices
 * @param mat1 first matrix
 * @param mat2 second matrix
 * @param matOutput output matrix (is it bad form to do this? idk)
 * @param rows number of rows in each matrix
 * @param cols number of cols in each matrix
 */
void matAdd(int** mat1, int** mat2, int** matOutput, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matOutput[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}

/**
 * Subtracts two same size matrices
 * @param mat1 first matrix
 * @param mat2 second matrix
 * @param matOutput output matrix (is it bad form to do this? idk)
 * @param rows number of rows in each matrix
 * @param cols number of cols in each matrix
 */
void matSub(int** mat1, int** mat2, int** matOutput, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matOutput[i][j] = mat1[i][j]-mat2[i][j];
        }
    }
}

/**
 * prints vector
 * @param vector vector to print
 * @param size size of vector
 */
void vecPrint(int* vector, int size){
    for(int i=0;i<size; i++){
        printf("%d \n", vector[i]);
    }
}

void matPrint(int** matrix, int rows, int cols){
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols;j++){
            printf("%d \n", matrix[i][j]);
        }
    }
}

/**
 * frees vector
 * @param vector vector to print
 * @param size size of vector
 */
void vecFree(int* vector, int size){
    for(int i=0; i<size; i++){
        free(vector[i]);
    }
    free(vector);
    vector = NULL;
}

/**
 * frees matrix
 * @param matrix vector to print
 * @param size size of vector
 */
void matFree(int** matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols;j++){
            free(matrix[i][j]);
        }
    }
    free(matrix);
    matrix = NULL;
}