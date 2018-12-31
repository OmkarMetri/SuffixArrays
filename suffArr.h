#include "client.h"

struct suffix { 
    int idx;
    int rank[2]; 
}; 
 
typedef struct suffix suf;

int compare(suf alpha, suf bravo);

int *SuffixArray(char *txt, int n);

void printArr(int arr[], int n);
