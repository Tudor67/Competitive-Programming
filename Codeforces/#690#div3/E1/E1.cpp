#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<int> count(n + 5, 0);
    for(int i = 1; i <= n; ++i){
        int elem;
        cin >> elem;
        count[elem] += 1;
    }

    long long answer = 0;
    for(int elem = 1; elem <= n; ++elem){
        long long c0 = count[elem];
        long long c1 = count[elem + 1];
        long long c2 = count[elem + 2];
        long long c000 = (c0 - 2) * (c0 - 1) * c0 / 6;
        long long c001 = (c0 - 1) * c0 / 2 * c1;
        long long c002 = (c0 - 1) * c0 / 2 * c2;
        long long c012 = c0 * (c1 + c2 - 1) * (c1 + c2) / 2;
        answer += c000 + c001 + c002 + c012;
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