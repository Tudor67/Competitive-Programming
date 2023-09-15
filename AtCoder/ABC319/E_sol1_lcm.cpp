#include <bits/stdc++.h>
using namespace std;

long long solve(long long startTime, long long X, long long Y,
                vector<long long>& P, vector<long long>& T){
    long long currentTime = startTime;
    currentTime += X;
    
    for(int i = 0; i < (int)P.size(); ++i){
        long long quotient = (currentTime + P[i] - 1 ) / P[i];
        currentTime = quotient * P[i] + T[i];
    }

    currentTime += Y;
    return currentTime;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, X, Y;
    cin >> N >> X >> Y;

    vector<long long> P(N - 1);
    vector<long long> T(N - 1);
    for(int i = 0; i < N - 1; ++i){
        cin >> P[i] >> T[i];
    }

    long long LCM = 1;
    for(int i = 0; i < N - 1; ++i){
        LCM = lcm(LCM, P[i]);
    }

    vector<long long> res(LCM);
    for(int i = 0; i < LCM; ++i){
        res[i] = solve(i, X, Y, P, T);
    }

    long long Q;
    cin >> Q;

    for(int i = 0; i < Q; ++i){
        long long q;
        cin >> q;

        long long currentResult = (q / LCM) * LCM + res[q % LCM];
        cout << currentResult << "\n";
    }

    return 0;
}