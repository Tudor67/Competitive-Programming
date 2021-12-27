#include <bits/stdc++.h>
using namespace std;

void quickSelect(const int& L, const int& K, const int& R, vector<int>& v){
    int randIdx = L + rand() % (R - L + 1);
    swap(v[randIdx], v[R]);

    int pivot = v[R];
    int l = L;
    int r = R - 1;
    while(l <= r){
        if(v[l] < pivot){
            ++l;
        }else{
            swap(v[l], v[r]);
            --r;
        }
    }

    int pivotIdx = l;
    swap(v[pivotIdx], v[R]);

    if(K == pivotIdx){
        return;
    }else if(K < pivotIdx){
        quickSelect(L, K, pivotIdx - 1, v);
    }else if(K > pivotIdx){
        quickSelect(pivotIdx + 1, K, R, v);
    }
}

int main(){
    ifstream cin("sdo.in");
    ofstream cout("sdo.out");

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    srand(time(NULL));
    quickSelect(0, k - 1, n - 1, v);

    cout << v[k - 1];

    cin.close();
    cout.close();
    return 0;
}