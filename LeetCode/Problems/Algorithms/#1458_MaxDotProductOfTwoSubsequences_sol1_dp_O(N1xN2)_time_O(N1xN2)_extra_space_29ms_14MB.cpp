class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int INF = 1e9;

        // dp[i][j]: max dot product of two subsequences of nums1[i .. N1 - 1] and nums2[j .. N2 - 1]
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, -INF));
        for(int i = N1 - 1; i >= 0; --i){
            for(int j = N2 - 1; j >= 0; --j){
                dp[i][j] = max({dp[i + 1][j],
                                dp[i][j + 1],
                                nums1[i] * nums2[j] + max(0, dp[i + 1][j + 1])});
            }
        }

        return dp[0][0];
    }
};