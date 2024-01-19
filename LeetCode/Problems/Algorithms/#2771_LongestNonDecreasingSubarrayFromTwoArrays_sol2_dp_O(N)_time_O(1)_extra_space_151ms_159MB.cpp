class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        
        int res = 1;
        int dp1 = 1; // max length of a subarray ending with nums1[i]
        int dp2 = 1; // max length of a subarray ending with nums2[i]

        for(int i = 1; i < N; ++i){
            int t11 = (nums1[i - 1] <= nums1[i] ? dp1 + 1 : 1);
            int t21 = (nums2[i - 1] <= nums1[i] ? dp2 + 1 : 1);
            int t12 = (nums1[i - 1] <= nums2[i] ? dp1 + 1 : 1);
            int t22 = (nums2[i - 1] <= nums2[i] ? dp2 + 1 : 1);

            dp1 = max(t11, t21);
            dp2 = max(t12, t22);

            res = max(res, max(dp1, dp2));
        }
        
        return res;
    }
};