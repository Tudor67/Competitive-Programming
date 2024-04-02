class Solution {
private:
    const int INF = 1e9;

    int computeMinChanges(string& s, int l, int r){
        const int LEN = r - l + 1;
        if(LEN <= 1){
            return INF;
        }

        int minChanges = INF;
        for(int d = 1; d * d <= LEN; ++d){
            if(LEN % d == 0){
                for(int divisor: {d, LEN / d}){
                    int changes = 0;
                    for(int startIndex = l; startIndex < l + divisor; ++startIndex){
                        int endIndex = r + 1 + (startIndex - l) - divisor;
                        for(int i = startIndex, j = endIndex; i < j; i += divisor, j -= divisor){
                            changes += (int)(s[i] != s[j]);
                        }
                    }
                    if(divisor != LEN){
                        minChanges = min(minChanges, changes);
                    }
                }
            }
        }

        return minChanges;
    }

public:
    int minimumChanges(string s, int k) {
        const int N = s.length();

        // minChanges[i][j]: min letter changes to make s[i .. j] semi-palindrome
        vector<vector<int>> minChanges(N, vector<int>(N, INF));
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                minChanges[i][j] = computeMinChanges(s, i, j);
            }
        }

        // dp[p][i]: min letter changes to partition s[0 .. i] in p substrings
        //           such that each substring is a semi-palindrome
        vector<vector<int>> dp(k + 1, vector<int>(N, INF));
        for(int i = 0; i < N; ++i){
            dp[1][i] = minChanges[0][i];
        }

        for(int p = 2; p <= k; ++p){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < i; ++j){
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + minChanges[j + 1][i]);
                }
            }
        }

        return dp[k][N - 1];
    }
};