#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int x;
    cin >> x;

    string s;
    int maxDigit = 9;
    while(x > 0 && maxDigit > 0){
        if(x > maxDigit){
            s += char('0' + maxDigit);
            x -= maxDigit;
            maxDigit -= 1;
        }else{
            s += char('0' + x);
            x = 0;
        }
    }

    if(x == 0){
        reverse(s.begin(), s.end());
    }else{
        s = "-1";
    }

    cout << s << "\n";
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