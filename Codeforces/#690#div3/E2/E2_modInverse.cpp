#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;
const long long MODULO = 1e9 + 7;

vector<long long> getFactorialValues(int n){
    vector<long long> factorial(n + 1);
    factorial[0] = 1;
    for(int i = 1; i <= n; ++i){
        factorial[i] = (i * factorial[i - 1]) % MODULO;
    }
    return factorial;
}

long long modInverse(long long a){
    a %= MODULO;
    long long n = MODULO - 2;
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = (res * a) % MODULO;
        }
        a = (a * a) % MODULO;
        n /= 2;
    }
    return res;
}

long long nCk(long long n, long long k){
    static vector<long long> factorial = getFactorialValues(MAX_N);
    return (k <= n ? factorial[n] * modInverse(factorial[n - k] * factorial[k]) % MODULO : 0);
}

void solve(istream& cin, ostream& cout){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long answer = 0;
    for(int p1 = 0, p2 = 0; p1 < n; ++p1){
        while(p2 < n && a[p2] - a[p1] <= k){
            p2 += 1;
        }
        answer += nCk(p2 - p1 - 1, m - 1);
        answer %= MODULO;
    }

    cout << answer << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}