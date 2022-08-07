class Solution {
private:
    int solve(vector<int>& nums, int target, vector<int>& memo){
        if(target <= 0){
            return (target == 0);
        }
        
        if(memo[target] != -1){
            return memo[target];
        }
        
        memo[target] = 0;
        for(int num: nums){
            memo[target] += solve(nums, target - num, memo);
        }
        
        return memo[target];
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return solve(nums, target, memo);
    }
};