class Solution {
private:
    bool isValid(char c){
        return (isdigit(c) && c >= '1');
    }
    
    bool isValid(char c1, char c2){
        return (isdigit(c1) && isdigit(c2) && !(c1 == '0' || c1 >= '3' || (c1 == '2' && c2 >= '7')));
    }
    
public:
    int numDecodings(string s) {
        const int N = s.length();
        // dp[i]: number of ways to decode s[0 .. i]
        vector<int> dp(N, 0);
        dp[0] = isValid(s[0]);
        for(int i = 1; i < N; ++i){
            dp[i] += isValid(s[i]) * (i >= 1 ? dp[i - 1] : 1);
            dp[i] += isValid(s[i - 1], s[i]) * (i >= 2 ? dp[i - 2] : 1);
        }
        return dp[N - 1];
    }
};