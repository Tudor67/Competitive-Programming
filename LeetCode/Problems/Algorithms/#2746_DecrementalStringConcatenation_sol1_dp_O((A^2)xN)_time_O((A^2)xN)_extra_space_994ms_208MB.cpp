class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        const int N = words.size();
        const int A = 26;
        const int INF = 1e9;
        
        // dp[firstCharId][lastCharId][i]: min concatenated length for words[0 .. i]
        //                                 when firstCharId and lastCharId are the first and the last char ids
        //                                 of the corresponding concatenated string
        vector<vector<vector<int>>> dp(A, vector<vector<int>>(A, vector<int>(N, INF)));
        dp[words[0].front() - 'a'][words[0].back() - 'a'][0] = words[0].length();
        
        for(int i = 1; i < N; ++i){
            const int L = words[i].length();
            char firstChar = words[i].front();
            char lastChar = words[i].back();
            
            for(char c1 = 'a'; c1 <= 'z'; ++c1){
                for(char c2 = 'a'; c2 <= 'z'; ++c2){
                    dp[c1 - 'a'][lastChar - 'a'][i] = min(dp[c1 - 'a'][lastChar - 'a'][i],
                                                          dp[c1 - 'a'][c2 - 'a'][i - 1] + L - (int)(c2 == firstChar));
                }
            }
            
            for(char c1 = 'a'; c1 <= 'z'; ++c1){
                for(char c2 = 'a'; c2 <= 'z'; ++c2){
                    dp[firstChar - 'a'][c2 - 'a'][i] = min(dp[firstChar - 'a'][c2 - 'a'][i],
                                                           L - (int)(lastChar == c1) + dp[c1 - 'a'][c2 - 'a'][i - 1]);
                }
            }
        }
        
        int res = INF;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                res = min(res, dp[c1 - 'a'][c2 - 'a'][N - 1]);
            }
        }
        
        return res;
    }
};