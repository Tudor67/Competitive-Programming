#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    string a, b;
    cin >> a >> b;

    const int A_LENGTH = a.length();
    const int B_LENGTH = b.length();

    a = "#" + a;
    b = "#" + b;

    vector<vector<int>> dp(A_LENGTH + 1, vector<int>(B_LENGTH + 1, 0));
    int maxConsecutiveMatches = 0;
    for(int i = 1; i <= A_LENGTH; ++i){
        for(int j = 1; j <= B_LENGTH; ++j){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxConsecutiveMatches = max(dp[i][j], maxConsecutiveMatches);
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