#include "search.h"

int k;

int *search(char *pat, char *txt, int *suffArr, int n){
	int *result= new int[n];
    k = 0;
	int m = strlen(pat);
	for(int i=0; i < n; i++){
		int res = strncmp(pat, txt+suffArr[i], m);
		if (res==0){
			result[k++] = suffArr[i];
		}
	}
    if (k==0){
        result[k++] = -1;
    }
    return result;
}

