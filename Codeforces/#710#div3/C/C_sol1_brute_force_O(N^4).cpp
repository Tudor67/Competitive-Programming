#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    string a, b;
    cin >> a >> b;
    
    const int A_LENGTH = a.length();
    const int B_LENGTH = b.length();

    int answer = A_LENGTH + B_LENGTH;
    for(int i = 0; i < A_LENGTH; ++i){
        for(int j = i; j < A_LENGTH; ++j){
            string aSubstr = a.substr(i, j - i + 1);
            if(b.find(aSubstr) != string::npos){
                int cost = A_LENGTH + B_LENGTH - 2 * (j - i + 1);
                answer = min(cost, answer);
            }
        }
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