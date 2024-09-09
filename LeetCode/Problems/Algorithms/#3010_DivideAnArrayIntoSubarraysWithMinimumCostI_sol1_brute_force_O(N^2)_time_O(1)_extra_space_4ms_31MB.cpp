class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int N = nums.size();

        int minCost = nums[0] + nums[1] + nums[2];
        for(int i = 1; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                minCost = min(minCost, nums[0] + nums[i] + nums[j]);
            }
        }
        
        return minCost;
    }
};