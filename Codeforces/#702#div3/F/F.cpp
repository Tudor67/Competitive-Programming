#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    map<int, int> count;
    for(int i = 0; i < N; ++i){
        int elem;
        cin >> elem;
        count[elem] += 1;
    }

    const int M = count.size();
    vector<int> f(M + 2, 0);
    int idx = 0;
    for(const pair<int, int>& P: count){
        f[++idx] = P.second;
    }

    sort(f.begin() + 1, f.begin() + M + 1);

    vector<int> pref(M + 2);
    for(int i = 1; i <= M; ++i){
        pref[i] = pref[i - 1] + f[i];
    }

    vector<int> suf(M + 2);
    for(int i = M; i >= 1; --i){
        suf[i] = f[i] + suf[i + 1];
    }

    int answer = INT_MAX;
    for(int i = 1; i <= M; ++i){
        int cost = pref[i - 1] + (suf[i + 1] - f[i] * (M - i));
        answer = min(cost, answer);
    }

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