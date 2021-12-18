#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    int m = pattern.size();

    // maxSuffixPrefix[j][c]:
    //   length of the longest suffix of newP = PATTERN[0 .. j - 1] + c;
    //   which is also a prefix of PATTERN
    vector<vector<int>> maxSuffixPrefix(m + 1, vector<int>('Z' + 1));
    string newP;
    for(int j = 0; j <= m; ++j){
        if(j > 0){
            newP += pattern[j - 1];
        }
        for(char c = 'A'; c <= 'Z'; ++c){
            newP.push_back(c);
            for(int k = (int)newP.length(); k >= 1; --k){
                if(pattern.compare(0, k, newP, (int)newP.length() - k) == 0){
                    maxSuffixPrefix[j][c] = k;
                    break;
                }
            }
            newP.pop_back();
        }
    }

    // dp[i][j]: number of bad strings of length i
    //           ending with pattern[0 .. j - 1] of length j
    //           (these strings do not include pattern as their substring)
    const long long MODULO = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    dp[0][0] = 1;
    for(int i = 0; i <= n - 1; ++i){
        for(int j = 0; j <= m - 1; ++j){
            for(char c = 'A'; c <= 'Z'; ++c){
                int nextJ = maxSuffixPrefix[j][c];
                dp[i + 1][nextJ] += dp[i][j];
                dp[i + 1][nextJ] %= MODULO;
            }
        }
    }
    
    long long totalStrings = 1;
    for(int i = 1; i <= n; ++i){
        totalStrings *= 26;
        totalStrings %= MODULO;
    }

    long long badStrings = 0;
    for(int j = 0; j <= m - 1; ++j){
        badStrings += dp[n][j];
        badStrings %= MODULO;
    }

    long long answer = (totalStrings - badStrings + MODULO) % MODULO;
    cout << answer;

    return 0;
}