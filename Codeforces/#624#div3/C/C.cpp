#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

void solve(const int& n, const int& m, const string& s, const vector<int>& p, ostream& cout){
    vector<int> suffix_sum(n, 0);
    vector<int> sol(26, 0);

    for(int pos: p){
        ++suffix_sum[pos - 1];
    }
    ++suffix_sum[n - 1];

    for(int i = n - 2; i >= 0; --i){
        suffix_sum[i] += suffix_sum[i + 1];
    }

    for(int i = 0; i < n; ++i){
        sol[s[i] - 'a'] += suffix_sum[i];
    }

    for(int i = 0; i < 26; ++i){
        cout << sol[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    int t, n, m;
    string s;
    vector<int> p;

    cin >> t;

    for(; t > 0; --t){
        cin >> n >> m;
        cin >> s;

        p.resize(m);
        for(int i = 0; i < m; ++i){
            cin >> p[i];
        }

        solve(n, m, s, p, cout);
    }

    return 0;
}