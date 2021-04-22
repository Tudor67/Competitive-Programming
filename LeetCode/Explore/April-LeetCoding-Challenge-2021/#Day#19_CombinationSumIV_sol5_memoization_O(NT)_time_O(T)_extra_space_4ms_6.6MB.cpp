class Solution {
private:
    int solve(int target, vector<int>& nums, vector<int>& memo){
        if(target <= 0){
            return (target == 0);
        }
        if(memo[target] == -1){
            int combinations = 0;
            for(int num: nums){
                combinations += solve(target - num, nums, memo);
            }
            memo[target] = combinations;
        }
        return memo[target];
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return solve(target, nums, memo);
    }
};