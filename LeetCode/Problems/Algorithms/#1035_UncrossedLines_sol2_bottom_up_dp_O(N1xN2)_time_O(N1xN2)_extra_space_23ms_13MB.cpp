class Solution {
private:
    int getVal(vector<vector<int>>& dp, int i, int j){
        if(0 <= i && i < (int)dp.size() && 0 <= j && j < (int)dp[i].size()){
            return dp[i][j];
        }
        return 0;
    }

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        // dp[i][j]: longest common subsequence of nums1[0 .. i] and nums2[0 .. j]
        vector<vector<int>> dp(N1, vector<int>(N2));
        for(int i = 0; i < N1; ++i){
            for(int j = 0; j < N2; ++j){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + getVal(dp, i - 1, j - 1);
                }else{
                    dp[i][j] = max(getVal(dp, i - 1, j), getVal(dp, i, j - 1));
                }
            }
        }

        return dp[N1 - 1][N2 - 1];
    }
};