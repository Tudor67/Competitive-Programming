#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    if(count(A.begin(), A.end(), A[0]) == N){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}