#include <bits/stdc++.h>
using namespace std;

const int MODULO = 1e9 + 7;

vector<long long> computeCombinations(int n, int k){
    // returns [0Ck, 1Ck, 2Ck, ..., nCk]
    vector<vector<long long>> nCk(2, vector<long long>(k + 1, 0));
    vector<long long> comb(n + 1);
    nCk[0][0] = 1;
    comb[0] = nCk[0][k];
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= min(k, i); ++j){
            nCk[i % 2][j] = (j - 1 >= 0 ? nCk[(i - 1) % 2][j - 1] : 0) + nCk[(i - 1) % 2][j];
            nCk[i % 2][j] %= MODULO;
        }
        comb[i] = nCk[i % 2][k];
    }
    return comb;
}

void solve(istream& cin, ostream& cout){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> comb = computeCombinations(n, m - 1);

    long long answer = 0;
    for(int p1 = 0, p2 = 0; p1 < n; ++p1){
        while(p2 < n && a[p2] - a[p1] <= k){
            p2 += 1;
        }
        if(p2 - p1 - 1 >= m - 1){
            answer += comb[p2 - p1 - 1];
            answer %= MODULO;
        }
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