class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int N = nums.size();

        int minCost = nums[0] + nums[1] + nums[2];
        int suffMin = nums[N - 1];
        for(int i = N - 2; i >= 1; --i){
            minCost = min(minCost, nums[0] + nums[i] + suffMin);
            suffMin = min(suffMin, nums[i]);
        }

        return minCost;
    }
};