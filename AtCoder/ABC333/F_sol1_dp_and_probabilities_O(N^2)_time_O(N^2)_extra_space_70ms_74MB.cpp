#include <bits/stdc++.h>
using namespace std;

const long long MODULO = 998244353;

long long fastPow(long long a, long long n){
    a %= MODULO;
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = (res * a) % MODULO;
        }
        a = (a * a) % MODULO;
        n >>= 1;
    }
    return res;
}

long long modInverse(long long a){
    return fastPow(a, MODULO - 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // dp[s][i]: probability that ith person will be the last remaining
    //           person in a line with initial size s
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1));
    dp[1][1] = 1;

    long long inverseOf2 = modInverse(2);
    for(int size = 2; size <= N; ++size){
        long long wSum = 0;
        long long p = inverseOf2;
        for(int i = size - 1; i >= 1; --i){
            wSum = (wSum + p * dp[size - 1][i]) % MODULO;
            p = (p * inverseOf2) % MODULO;
        }
        
        dp[size][size] = wSum * modInverse(MODULO + 1 - fastPow(inverseOf2, size)) % MODULO;
        
        dp[size][1] = inverseOf2 * dp[size][size] % MODULO;
        for(int i = 2; i <= size - 1; ++i){
            dp[size][i] = inverseOf2 * (dp[size - 1][i - 1] + dp[size][i - 1]) % MODULO;
        }
    }

    for(int i = 1; i <= N; ++i){
        cout << dp[N][i] << " ";
    }

    return 0;
}