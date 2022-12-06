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
        
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len <= 2 || isPalindrome[i + 1][j - 1]){
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
        
        // dp[i]: max number of non-overlapping palindromes (of length >= k) in s[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = getVal(dp, i - 1);
            for(int j = i - k + 1; j >= 0; --j){
                if(isPalindrome[j][i]){
                    dp[i] = max(dp[i], 1 + getVal(dp, j - 1));
                    break;
                }
            }
        }
        
        return dp[N - 1];
    }
};