#include "suffArr.h"
#include "timer.h"
#include "search.h"
#include "client.h"

int main() { 
    string line;
    ifstream fin;
    fin.open("data.txt");
    getline(fin, line);
    fin.close();
    
    char *text = new char[line.length()];
    strcpy(text, line.c_str());
    int n = strlen(text);

    unsigned long long t0,t1;

    t0 = rdtsc();
    int *suffixArr = SuffixArray(text, n);
    t1 = rdtsc();
    cout << (t1-t0)/FREQ << endl;

    int t; cin >> t;
    
    for (int i=0; i<=t; i++){
        if (i==0){ getline(cin, line); continue;}

        getline(cin, line);
        char *pattern = new char[line.length()];
        strcpy(pattern, line.c_str()); 
        
        t0=rdtsc();   
        int *r = search(pattern, text, suffixArr, n);
        t1=rdtsc();

        sort(r, r+k);
        printArr(r, k);
        cout << (t1-t0)/FREQ << endl;
         
        delete[] pattern;
        delete[] r;
    }
    
    delete[] text;
    delete[] suffixArr;
    return 0; 
}