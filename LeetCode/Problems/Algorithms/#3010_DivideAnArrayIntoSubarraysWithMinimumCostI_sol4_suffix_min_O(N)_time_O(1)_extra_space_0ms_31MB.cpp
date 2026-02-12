class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int N = nums.size();

        int minCost = nums[0] + nums[1] + nums[2];
        int suffMin = nums[N - 1];
        for(int i = N - 2; i >= 1; --i){
            int currCost = nums[0] + nums[i] + suffMin;
            minCost = min(minCost, currCost);
            suffMin = min(suffMin, nums[i]);
        }

        return minCost;
    }
};