#include "brojPutevaDP.h"
using namespace std;

// a)
int brojMogucihPuteva(int m, int n) {

    vector<vector<int>> DP(m, vector<int> (n, 0));
    int k = min(m, n);

    for(int i = 0; i < k; i ++)
            DP[i][i] = 1;

    for(int j = 0; j < n; j ++)
        for(int i = 0; i < j; i ++) {
            DP[i][j] += DP[i][j-1];
            if(i + 1 < m) DP[i][j] += DP[i+1][j-1];
            if(i - 1 >= 0) DP[i][j] += DP[i-1][j-1];
        }

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }

    return DP[0][n-1];
}

// b)
int brojMogucihPutevaSaZabranama(vector<vector<bool>> zabrane) {

    int m = zabrane.size();
    int n = zabrane[0].size();

    vector<vector<int>> DP(m, vector<int> (n, 0));

    int k = min(m, n);

    for(int i = 0; i < k; i ++)
            DP[i][i] = 1;

    for(int j = 0; j < n; j ++)
        for(int i = 0; i < j; i ++) {
            if(zabrane[i][j]) continue;
            DP[i][j] += DP[i][j-1];
            if(i + 1 < m) DP[i][j] += DP[i+1][j-1];
            if(i - 1 >= 0) DP[i][j] += DP[i-1][j-1];
        }

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }

    return DP[0][n-1];
}

// c)
void backtrack(int m, int n, int i, int j, vector<int> &put, const vector<int> &indeksi, int &brojac) {

    if (i >= m || i < 0 || j < 0 || j >= n || i > j)
        return;

    put.push_back(i);

    if (i == 0 && j == n - 1) {
        int p = 0, q = 0;
        while (p < put.size() && q < indeksi.size()) {
            if (put[p] == indeksi[q]) {
                q++;
                if (q == indeksi.size()) {
                    brojac++;
                    break;
                }
            }
            p++;
        }

    } else {
        backtrack(m, n, i, j + 1, put, indeksi, brojac);
        backtrack(m, n, i - 1, j + 1, put, indeksi, brojac);
        backtrack(m, n, i + 1, j + 1, put, indeksi, brojac);
    }

    put.pop_back();
}

int brojMogucihPutevaSaIndeksima1(int m, int n, vector<int> indeksi) {

    vector<int> put;
    int brojac = 0;

    backtrack(m, n, 0, 0, put, indeksi, brojac);

    return brojac;
}

int brojMogucihPutevaSaIndeksima2(int m, int n, vector<int> indeksi) {
    vector<vector<Putanje>> DP(m, vector<Putanje>(n));
    DP[0][0].putanje = {{0}};
    int k = min(m, n);

    for(int i = 1; i < k; i ++)
        for (auto p : DP[i - 1][i - 1].putanje) {
            p.push_back(i);
            DP[i][i].putanje.push_back(p);
        }

    for (int j = 0; j < n; j++)
        for (int i = 0; i < j; i++) {

            for (auto p : DP[i][j - 1].putanje) {
                p.push_back(i);
                DP[i][j].putanje.push_back(p);
            }

            if (i + 1 < m)
                for (auto p : DP[i + 1][j - 1].putanje) {
                    p.push_back(i);
                    DP[i][j].putanje.push_back(p);
                }


            if (i - 1 >= 0)
                for (auto p : DP[i - 1][j - 1].putanje) {
                    p.push_back(i);
                    DP[i][j].putanje.push_back(p);
                }
        }
    //ispisujem sve moguce putanje radi testiranja
    for (auto &put : DP[0][n - 1].putanje) {
        for (int k = 0; k < put.size(); k++)
            cout << put[k] << " ";
        cout << endl;
    }

    int brojac = 0;

    for (auto put : DP[0][n - 1].putanje) {
        int p = 0, q = 0;
        while (p < put.size() && q < indeksi.size()) {
            if (put[p] == indeksi[q]) {
                q++;
                if (q == indeksi.size()) {
                    brojac++;
                    break;
                }
            }
            p++;
        }
    }

    return brojac;
}

