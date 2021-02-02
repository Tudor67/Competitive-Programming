#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    int answer = 0;
    for(int i = 1; i <= N; ++i){
        int l = i;
        int r = i;
        for(; 1 <= l && A[l] >= A[i]; --l);
        for(; r <= N && A[i] <= A[r]; ++r);
        answer = max(A[i] * (r - l - 1), answer);
    }

    cout << answer;

    return 0;
}