class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        
        int res = 1;
        int dp1 = 1; // max length of a subarray ending with nums1[i]
        int dp2 = 1; // max length of a subarray ending with nums2[i]

        for(int i = 1; i < N; ++i){
            int prevDP1 = dp1;
            int prevDP2 = dp2;

            dp1 = 1;
            if(nums1[i - 1] <= nums1[i]){
                dp1 = max(dp1, prevDP1 + 1);
            }
            if(nums2[i - 1] <= nums1[i]){
                dp1 = max(dp1, prevDP2 + 1);
            }
            
            dp2 = 1;
            if(nums1[i - 1] <= nums2[i]){
                dp2 = max(dp2, prevDP1 + 1);
            }
            if(nums2[i - 1] <= nums2[i]){
                dp2 = max(dp2, prevDP2 + 1);
            }
            
            res = max(res, max(dp1, dp2));
        }
        
        return res;
    }
};