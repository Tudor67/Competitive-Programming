#include <bits/stdc++.h>
using namespace std;

int factorial(const int& N, const int& MODULO){
    int factorial = 1;
    for(long long i = 1; i <= N; ++i){
        factorial = (i * factorial) % MODULO;
    }
    return factorial;
}

int modInverse(long long a, const int& MODULO){
    int n = MODULO - 2;
    int res = 1;
    while(n){
        if(n & 1){
            res = (res * a) % MODULO;
        }
        a = (a * a) % MODULO;
        n >>= 1;
    }
    return res;
}

int nCk(const int& N, const int& K, const int& MODULO){
    long long fN = factorial(N, MODULO);
    long long fKi  = modInverse(factorial(K, MODULO), MODULO);
    long long fNKi = modInverse(factorial(N - K, MODULO), MODULO);
    return (fN * ((fKi * fNKi) % MODULO)) % MODULO;
}

void solve(istream& cin, ostream& cout){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    
    int l = k - 1;
    for(; 0 <= l && a[l] == a[k - 1]; --l);
    l += 1;

    int r = k - 1;
    for(; r <= n - 1 && a[k - 1] == a[r]; ++r);
    r -= 1;

    const int MODULO = 1e9 + 7;
    int answer = nCk(r - l + 1, k - l, MODULO);

    cout << answer << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}