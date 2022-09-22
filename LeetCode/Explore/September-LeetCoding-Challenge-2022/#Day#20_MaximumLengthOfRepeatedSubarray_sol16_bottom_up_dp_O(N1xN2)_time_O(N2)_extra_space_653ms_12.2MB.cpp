class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        // At N1th iteration:
        //    dp[N1 % 2][N2]: length of max matching subarrays nums1[.. N1 - 1] and nums2[.. N2 - 1]
        //                    ending in nums1[N1 - 1] and nums2[N2 - 1]
        vector<vector<int>> dp(2, vector<int>(N2 + 1));
        int maxMatch = 0;
        for(int i1 = 1; i1 <= N1; ++i1){
            for(int i2 = 1; i2 <= N2; ++i2){
                if(nums1[i1 - 1] == nums2[i2 - 1]){
                    dp[i1 % 2][i2] = dp[(i1 - 1) % 2][i2 - 1] + 1;
                    maxMatch = max(maxMatch, dp[i1 % 2][i2]);
                }else{
                    dp[i1 % 2][i2] = 0;
                }
            }
        }
        
        return maxMatch;
    }
};