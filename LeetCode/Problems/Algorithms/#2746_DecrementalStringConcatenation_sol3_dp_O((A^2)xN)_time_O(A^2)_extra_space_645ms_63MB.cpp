class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        const int N = words.size();
        const int A = 26;
        const int INF = 1e9;
        
        // At ith iteration:
        // DP[i % 2][firstCharId][lastCharId]: min concatenated length for words[0 .. i]
        //                                     when firstCharId and lastCharId are the first and the last char ids
        //                                     of the corresponding concatenated string
        vector<vector<vector<int>>> DP(2, vector<vector<int>>(A, vector<int>(A, INF)));
        DP[0][words[0].front() - 'a'][words[0].back() - 'a'] = words[0].length();
        
        for(int i = 1; i < N; ++i){
            const int L = words[i].length();
            char firstChar = words[i].front();
            char lastChar = words[i].back();

            vector<vector<int>>& prevDp = DP[(i - 1) % 2];
            vector<vector<int>>& dp = DP[i % 2];

            for(char c1 = 'a'; c1 <= 'z'; ++c1){
                for(char c2 = 'a'; c2 <= 'z'; ++c2){
                    dp[c1 - 'a'][c2 - 'a'] = INF;
                }
            }
            
            for(char c1 = 'a'; c1 <= 'z'; ++c1){
                for(char c2 = 'a'; c2 <= 'z'; ++c2){
                    dp[c1 - 'a'][lastChar - 'a'] = min(dp[c1 - 'a'][lastChar - 'a'],
                                                       prevDp[c1 - 'a'][c2 - 'a'] + L - (int)(c2 == firstChar));
                }
            }
            
            for(char c1 = 'a'; c1 <= 'z'; ++c1){
                for(char c2 = 'a'; c2 <= 'z'; ++c2){
                    dp[firstChar - 'a'][c2 - 'a'] = min(dp[firstChar - 'a'][c2 - 'a'],
                                                        L - (int)(lastChar == c1) + prevDp[c1 - 'a'][c2 - 'a']);
                }
            }
        }
        
        int res = INF;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                res = min(res, DP[(N - 1) % 2][c1 - 'a'][c2 - 'a']);
            }
        }
        
        return res;
    }
};