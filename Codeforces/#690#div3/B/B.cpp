#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool found = false;
    for(int i = 0, j = n - 4; i <= 4; ++i, ++j){
        string ss = s.substr(0, i) + s.substr(j);
        if(ss == "2020"){
            found = true;
            break;
        }
    }

    if(found){
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