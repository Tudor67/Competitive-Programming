#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    long long n;
    cin >> n;

    if((n & (n - 1)) != 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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