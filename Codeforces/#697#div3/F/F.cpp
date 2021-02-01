#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<string> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    for(int j = 0; j < n; ++j){
        if(a[0][j] != b[0][j]){
            for(int i = 0; i < n; ++i){
                a[i][j] = '0' + (a[i][j] - '0') ^ 1;
            }
        }
    }

    for(int i = 1; i < n; ++i){
        if(a[i][0] != b[i][0]){
            for(int j = 0; j < n; ++j){
                a[i][j] = '0' + (a[i][j] - '0') ^ 1;
            }
        }
    }

    string answer = (a == b ? "YES" : "NO");
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