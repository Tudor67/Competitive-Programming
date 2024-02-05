class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        const int N = nums1.size();
        const int NUMS1_SUM = accumulate(nums1.begin(), nums1.end(), 0);
        const int NUMS2_SUM = accumulate(nums2.begin(), nums2.end(), 0);

        if(NUMS1_SUM <= x){
            return 0;
        }

        vector<pair<int, int>> nums(N);
        for(int i = 0; i < N; ++i){
            nums[i] = {nums1[i], nums2[i]};
        }

        sort(nums.begin(), nums.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 return (LHS.second < RHS.second);
             });

        // At kth iteration:
        //    dp[k % 2][i]: max total value that can be reduced in k operations from nums[0 .. i]
        vector<vector<int>> dp(2, vector<int>(N));
        for(int k = 1; k <= N; ++k){
            dp[k % 2][0] = nums[0].first + k * nums[0].second;
            for(int i = 1; i < N; ++i){
                dp[k % 2][i] = max(dp[(k - 1) % 2][i - 1] + nums[i].first + k * nums[i].second,
                                   dp[k % 2][i - 1]);
            }

            if(NUMS1_SUM + k * NUMS2_SUM - dp[k % 2][N - 1] <= x){
                return k;
            }
        }

        return -1;
    }
};