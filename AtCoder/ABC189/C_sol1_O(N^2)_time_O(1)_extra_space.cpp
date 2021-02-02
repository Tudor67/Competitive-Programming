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
        int x = A[i];
        for(int j = i; j <= N; ++j){
            x = min(A[j], x);
            answer = max(x * (j - i + 1), answer);
        }
    }

    cout << answer;

    return 0;
}