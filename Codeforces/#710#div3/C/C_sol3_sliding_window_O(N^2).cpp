#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    string a, b;
    cin >> a >> b;

    const int A_LENGTH = a.length();
    const int B_LENGTH = b.length();

    int maxConsecutiveMatches = 0;
    for(int shift = -A_LENGTH; shift < B_LENGTH; ++shift){
        int consecutiveMatches = 0;
        for(int i = 0; i < A_LENGTH && i + shift < B_LENGTH; ++i){
            if(0 <= i + shift){
                if(a[i] == b[i + shift]){
                    consecutiveMatches += 1;
                    maxConsecutiveMatches = max(consecutiveMatches, maxConsecutiveMatches);
                }else{
                    consecutiveMatches = 0;
                }
            }
        }
    }

    int answer = A_LENGTH + B_LENGTH - 2 * maxConsecutiveMatches;

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