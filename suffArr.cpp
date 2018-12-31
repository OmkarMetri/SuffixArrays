#include "suffArr.h"

int compare(suf alpha, suf bravo) { 
    return (alpha.rank[0] == bravo.rank[0])? (alpha.rank[1] < bravo.rank[1] ?1: 0): (alpha.rank[0] < bravo.rank[0] ?1: 0); 
} 

int *SuffixArray(char *txt, int n) { 
    suf* suf_struct_array = new suf[n];
    for (int i = 0; i < n; i++) { 
        suf_struct_array[i].idx = i; 
        suf_struct_array[i].rank[0] = txt[i] - 'a'; 
        suf_struct_array[i].rank[1] = ((i+1) < n)? (txt[i+1] - 'a'): -1; 
    }
   
    sort(suf_struct_array, suf_struct_array+n, compare);
    
    int *ind = new int[n]; 
    for (int k = 4; k < 2*n; k = k*2) { 
        int rank = 0; 
        int prev = suf_struct_array[0].rank[0]; 
        suf_struct_array[0].rank[0] = rank; 
        ind[suf_struct_array[0].idx] = 0; 

        for (int i = 1; i < n; i++) { 
            if (suf_struct_array[i].rank[0] == prev && suf_struct_array[i].rank[1] == suf_struct_array[i-1].rank[1]) { 
                prev = suf_struct_array[i].rank[0]; 
                suf_struct_array[i].rank[0] = rank; 
            } 
            else { 
                prev = suf_struct_array[i].rank[0]; 
                suf_struct_array[i].rank[0] = ++rank; 
            } 
            ind[suf_struct_array[i].idx] = i; 
        } 
  
        for (int i = 0; i < n; i++) { 
            int nextindex = suf_struct_array[i].idx + k/2; 
            suf_struct_array[i].rank[1] = (nextindex < n)? suf_struct_array[ind[nextindex]].rank[0]: -1; 
        } 
        sort(suf_struct_array, suf_struct_array+n, compare); 
    } 
  
    int *arr = new int[n]; 
    for (int i = 0; i < n; i++) 
        arr[i] = suf_struct_array[i].idx; 
    delete[] suf_struct_array;
    return  arr; 
}

void printArr(int arr[], int n) { 
    for (int i = 0; i<n; i++) 
        cout << arr[i] << ", "; 
} 
