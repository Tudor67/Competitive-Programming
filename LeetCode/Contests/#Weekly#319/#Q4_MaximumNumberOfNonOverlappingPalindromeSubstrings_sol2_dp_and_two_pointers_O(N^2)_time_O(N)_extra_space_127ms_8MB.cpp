class Solution {
private:
    int getVal(vector<int>& dp, int i){
        if(i < 0 || i >= (int)dp.size()){
            return 0;
        }
        return dp[i];
    }
    
public:
    int maxPalindromes(string s, int k) {
        const int N = s.length();
        
        // dp[i]: max number of non-overlapping palindromes (of length >= k) in s[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = max(dp[i], getVal(dp, i - 1));
            for(const pair<int, int> START_INDICES: vector<pair<int, int>>{{i - 1, i}, {i, i}}){
                int l = START_INDICES.first;
                int r = START_INDICES.second;
                while(0 <= l && r <= N - 1 && s[l] == s[r]){
                    int len = r - l + 1;
                    if(len >= k){
                        dp[r] = max(dp[r], getVal(dp, l - 1) + 1);
                    }
                    l -= 1;
                    r += 1;
                }
            }
        }
        
        return dp[N - 1];
    }
};