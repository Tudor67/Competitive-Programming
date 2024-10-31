class Solution {
private:
    vector<int> computeLIS(vector<int> nums){
        const int N = nums.size();

        vector<int> lis(N);
        vector<int> dp;
        for(int i = 0; i < N; ++i){
            int j = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(j >= (int)dp.size()){
                dp.resize(j + 1);
            }
            dp[j] = nums[i];
            lis[i] = j + 1;
        }

        return lis;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int N = nums.size();

        vector<int> leftLIS = computeLIS(nums);
        vector<int> rightLIS = computeLIS(vector<int>(nums.rbegin(), nums.rend()));
        reverse(rightLIS.begin(), rightLIS.end());

        int maxMountainSize = 0;
        for(int i = 1; i + 1 < N; ++i){
            if(leftLIS[i] >= 2 && rightLIS[i] >= 2){
                int mountainSize = leftLIS[i] + rightLIS[i] - 1;
                maxMountainSize = max(maxMountainSize, mountainSize);
            }
        }

        return (N - maxMountainSize);
    }
};