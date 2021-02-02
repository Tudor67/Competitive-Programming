#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector<int> V(N + 1);
    vector<int> P(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> V[i] >> P[i];
    }

    int answer = -1;
    int prefSum = 0;
    X *= 100;
    for(int i = 1; i <= N; ++i){
        prefSum += V[i] * P[i];
        if(prefSum > X){
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}