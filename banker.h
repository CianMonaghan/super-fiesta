#define MAX 5
#define PROC 3
#define RES 5
typedef struct Process{
    int id;
    int done;
    int claims[MAX];
    int allocations[MAX];
    int needs[MAX];
} Process;