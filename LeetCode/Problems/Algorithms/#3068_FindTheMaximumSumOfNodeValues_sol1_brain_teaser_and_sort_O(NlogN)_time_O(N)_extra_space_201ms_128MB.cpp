class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int N = nums.size();

        vector<int> contrib(N);
        for(int i = 0; i < N; ++i){
            contrib[i] = (nums[i] ^ k) - nums[i];
        }

        sort(contrib.begin(), contrib.end());

        long long maxSum = accumulate(nums.begin(), nums.end(), (long long)0);
        for(int i = N - 1; i >= 1; i -= 2){
            if(contrib[i - 1] + contrib[i] >= 0){
                maxSum += contrib[i - 1] + contrib[i];
            }
        }

        return maxSum;
    }
};