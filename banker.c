#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

// Function to find the need of each process
void calculateNeed(int need[PROC][RES], int maxm[PROC][RES], int allot[PROC][RES]){
    for (int i = 0 ; i < PROC ; i++){
        for (int j = 0 ; j < RES ; j++) {
            need[i][j] = maxm[i][j] - allot[i][j];
        }
    }
}

// Function to find the system is in safe state or not
int* isSafe(int processes[PROC], int avail[RES], int maxm[PROC][RES], int allot[PROC][RES]){
    if(*maxm > RES || *allot > RES){
        printf("ERROR: array too big");
    }
    int flag=0;
    int np=0;
    int nr=0;
    int* safeSequence = malloc(MAX*sizeof(int));
    int** output;
    Process ps[MAX];
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < np; j++) {
            if (ps[j].done) continue;
            flag = 1;
            for (int k = 0; k < nr; k++) {
                if (ps[j].needs[k] > avail[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                for (int k = 0; k < nr; k++) {
                    avail[k] += ps[j].allocations[k];
                    ps[j].needs[k] = 0;
                    safeSequence[i] = ps[j].id;
                }
                ps[j].done = 1;
                break;
            }
            *output = safeSequence;
        }
    }
    while(safeSequence[1] != *output){
        isSafe(processes, avail, maxm, allot);
    }
    return output;
}