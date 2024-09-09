#ifndef BROJ_PUTEVA_H
#define BROJ_PUTEVA_H
#include<iostream>
#include<vector>
using namespace std;

struct Putanje {
    vector<vector<int>> putanje;
};

// a)
int brojMogucihPuteva(int m, int n);

// b)
int brojMogucihPutevaSaZabranama(vector<vector<bool>> zabrane);

// c)
void backtrack(int m, int n, int i, int j, vector<int> &put, const vector<int> &indeksi, int &brojac);
int brojMogucihPutevaSaIndeksima1(int m, int n, vector<int> indeksi);
int brojMogucihPutevaSaIndeksima2(int m, int n, vector<int> indeksi);



#endif // BROJ_PUTEVA_H
