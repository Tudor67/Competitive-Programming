class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int N = nums.size();

        long long maxSum = 0;
        vector<int> bonus(N);
        for(int i = 0; i < N; ++i){
            maxSum += nums[i];
            bonus[i] = (nums[i] ^ k) - nums[i];
        }

        sort(bonus.begin(), bonus.end());

        for(int i = N - 1; i - 1 >= 0; i -= 2){
            if(bonus[i - 1] + bonus[i] >= 1){
                maxSum += (bonus[i - 1] + bonus[i]);
            }
        }

        return maxSum;
    }
};