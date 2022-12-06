class Solution {
private:
    bool isPalindrome(const string& S, int l, int r){
        const int N = S.length();
        if(l > r || l < 0 || N <= r){
            return false;
        }
        while(l < r && S[l] == S[r]){
            l += 1;
            r -= 1;
        }
        return (l >= r);
    }
    
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
            dp[i] = getVal(dp, i - 1);
            if(isPalindrome(s, i - k + 1, i)){
                dp[i] = max(dp[i], getVal(dp, i - k) + 1);
            }
            if(isPalindrome(s, i - k, i)){
                dp[i] = max(dp[i], getVal(dp, i - k - 1) + 1);
            }
        }
        
        return dp[N - 1];
    }
};