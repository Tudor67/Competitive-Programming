class Solution {
public:
    int numDecodings(string s) {
        // At step i:
        // dp[0] - number of ways to decode s[0..i]
        // dp[1] - number of ways to decode s[0..i] if s[0..i] is valid and s[i] == '1'
        // dp[2] - number of ways to decode s[0..i] if s[0..i] is valid and s[i] == '2'
        vector<int> dp = {1, 0, 0};
        vector<int> dpNew = {0, 0, 0};
        for(char c: s){
            dpNew[0] = dp[0] * ('1' <= c) + dp[1] + dp[2] * (c <= '6');
            dpNew[1] = dp[0] * (c == '1');
            dpNew[2] = dp[0] * (c == '2');
            copy(dpNew.begin(), dpNew.end(), dp.begin());
        }
        return dp[0];
    }
};