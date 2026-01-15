class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int INF = 1e9;

        // dp[i1][i2]: max dot product for two subsequences from nums1[i1 .. N1 - 1] and nums2[i2 .. N2 - 1]
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, -INF));

        for(int i1 = N1 - 1; i1 >= 0; --i1){
            for(int i2 = N2 - 1; i2 >= 0; --i2){
                dp[i1][i2] = max({dp[i1 + 1][i2],
                                  dp[i1][i2 + 1],
                                  nums1[i1] * nums2[i2] + max(0, dp[i1 + 1][i2 + 1])});
            }
        }

        return dp[0][0];
    }
};