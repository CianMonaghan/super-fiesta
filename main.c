#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

int main(int argc, char *argv[])
{
  if(argc != 1){
    printf("Usage: ./bankers <system-state-file>");
  }
  FILE *file = fopen(argv[0], NULL);
  if(file==NULL){
    printf("No file found");
  }

  int nres =0; 	// number of resource types
  int nproc=0;	// number of processes
  fscanf(file, "%d", &nres);
  fscanf(file, "%d", &nproc);
  int* vec= (int*)malloc(nres*sizeof(int));
  int* mat= (int*)malloc(nres*sizeof(int));
  matClone(mat, nres, nproc);
  vecClone(vec, nres);

  matPrint(isSafe(vec, mat, mat, vec), nres, nproc);
  return 0;
}