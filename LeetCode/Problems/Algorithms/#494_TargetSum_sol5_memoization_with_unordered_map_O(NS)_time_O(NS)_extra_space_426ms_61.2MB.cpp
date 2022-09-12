class Solution {
private:
    int solve(int level, int sum, int target, vector<int>& nums, vector<unordered_map<int, int>>& memo){
        if(level == (int)nums.size()){
            return (sum == target);
        }else if(!memo[level].count(sum)){
            int addCount = solve(level + 1, sum - nums[level], target, nums, memo);
            int subtractCount = solve(level + 1, sum + nums[level], target, nums, memo);
            memo[level][sum] = addCount + subtractCount;
        }
        return memo[level][sum];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<unordered_map<int, int>> memo(N);
        return solve(0, 0, target, nums, memo);
    }
};