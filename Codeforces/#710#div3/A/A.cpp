#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    long long rows, cols, x;
    cin >> rows >> cols >> x;

    x -= 1;

    long long row = x % rows;
    long long col = x / rows;

    long long answer = row * cols + col + 1;

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