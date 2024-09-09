#include "BrojPutevaDP.cpp"

int main () {

   // cout<<brojMogucihPuteva(8, 6);

    vector<vector<bool>> zabrane;
    zabrane.push_back({0,0,1,0});
    zabrane.push_back({0,0,0,0});
    zabrane.push_back({1,0,1,0});
    zabrane.push_back({0,0,0,1});

   // cout<<brojMogucihPutevaSaZabranama(zabrane);

    cout<<brojMogucihPutevaSaIndeksima2(8, 6, {1, 2});

    //cout<<brojMogucihPutevaSaIndeksima1(5, 4, {1, 1});
}

