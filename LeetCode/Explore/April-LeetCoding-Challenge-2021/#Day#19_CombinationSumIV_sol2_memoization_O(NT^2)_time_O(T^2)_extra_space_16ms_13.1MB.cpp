class Solution {
private:
    int solve(int len, int target, vector<int>& nums, vector<vector<int>>& memo){
        if(len <= 0){
            return (target == 0);
        }
        if(target <= 0){
            return (target == 0);
        }
        if(memo[len][target] == -1){
            int combinations = 0;
            for(int num: nums){
                combinations += solve(len - 1, target - num, nums, memo);
            }
            memo[len][target] = combinations;
        }
        return memo[len][target];
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> memo(target + 1, vector<int>(target + 1, -1));
        return solve(target, target, nums, memo);
    }
};