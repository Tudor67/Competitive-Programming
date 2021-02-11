#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& a, const int& L, const int& R, long long& inversions){
    const int SIZE = R - L + 1;
    const int MID = (R + L) / 2;
    static vector<int> temp;
    if(SIZE >= 2){
        mergeSort(a, L, MID, inversions);
        mergeSort(a, MID + 1, R, inversions);
        temp.resize(max(SIZE, (int)temp.size()));
        for(int k = 0, i = L, j = MID + 1; k < SIZE; ++k){
            if(j > R || (i <= MID && a[i] <= a[j])){
                temp[k] = a[i++];
            }else{
                inversions += (MID + 1 - i);
                temp[k] = a[j++];
            }
        }
        copy(temp.begin(), temp.begin() + SIZE, a.begin() + L);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += 1;
    }

    long long inversions = 0;
    vector<int> aCopy = a;
    mergeSort(aCopy, 1, N, inversions);

    cout << inversions << "\n";
    for(int i = 1; i <= N - 1; ++i){
        inversions -= (a[i] - 1);
        inversions += (N - a[i]);
        cout << inversions << "\n";
    }

    return 0;
}