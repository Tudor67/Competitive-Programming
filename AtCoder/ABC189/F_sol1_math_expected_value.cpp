#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<bool> forward(N + 1, true);
    for(int i = 1; i <= K; ++i){
        int A;
        cin >> A;
        A += 1;
        forward[A] = false;
    }

    bool isPossible = true;
    int consecutiveReturns = 0;
    for(int i = 1; i <= N; ++i){
        consecutiveReturns = consecutiveReturns * !forward[i] + !forward[i];
        if(consecutiveReturns >= M){
            isPossible = false;
        }
    }

    if(isPossible){
        vector<double> xCoeff(N + 1, 0);
        vector<double> freeCoeff(N + 1, 0);
        double xCoeffSum = 0;
        double freeCoeffSum = 0;
        for(int i = N; i >= 2; --i){
            if(forward[i]){
                xCoeff[i] = xCoeffSum / M;
                freeCoeff[i] = 1 + freeCoeffSum / M;
            }else{
                xCoeff[i] = 1;
            }
            xCoeffSum += xCoeff[i];
            freeCoeffSum += freeCoeff[i];
            if(i + M <= N){
                xCoeffSum -= xCoeff[i + M];
                freeCoeffSum -= freeCoeff[i + M];
            }
        }
        double answer = (M + freeCoeffSum) / (M - xCoeffSum);
        cout << fixed << setprecision(5) << answer;
    }else{
        cout << "-1";
    }

    return 0;
}