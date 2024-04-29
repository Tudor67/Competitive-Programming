class Solution {
public:
    int longestIdealString(string s, int k) {
        const int N = s.length();
        const int A = 26;

        // At ith step:
        //    dp[j]: length of the longest valid subsequence of s[0 .. i]
        //           when the last letter of the subsequence is the jth lowercase letter
        vector<int> dp(A);
        for(int i = 0; i < N; ++i){
            int j = s[i] - 'a';
            dp[j] = *max_element(dp.begin() + max(0, j - k), dp.begin() + min(A, j + k + 1)) + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};