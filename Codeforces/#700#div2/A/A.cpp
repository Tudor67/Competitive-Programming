#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); ++i){
        if(i % 2 == 0){
            s[i] = (s[i] == 'a' ? 'b' : 'a');
        }else{
            s[i] = (s[i] == 'z' ? 'y' : 'z');
        }
    }

    cout << s << "\n";
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