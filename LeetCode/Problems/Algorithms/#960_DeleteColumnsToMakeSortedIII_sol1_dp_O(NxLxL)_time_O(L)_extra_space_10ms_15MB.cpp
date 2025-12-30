class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();

        // dp[i][0]: max length of increasing (not strictly increasing) subsequences
        //           from strs[0 .. N - 1][0 .. i]
        //           when we delete/skip the index i
        // dp[i][1]: max length of increasing (not strictly increasing) subsequences
        //           from strs[0 .. N - 1][0 .. i]
        //           when we keep/take the index i
        vector<vector<int>> dp(L, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = 1;

        for(int i = 1; i < L; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1;

            for(int j = 0; j < i; ++j){
                bool isInc = true;
                for(int strIdx = 0; strIdx < N; ++strIdx){
                    isInc = isInc && (strs[strIdx][j] <= strs[strIdx][i]);
                }
                if(isInc){
                    dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                }
            }
        }

        return L - max(dp[L - 1][0], dp[L - 1][1]);
    }
};