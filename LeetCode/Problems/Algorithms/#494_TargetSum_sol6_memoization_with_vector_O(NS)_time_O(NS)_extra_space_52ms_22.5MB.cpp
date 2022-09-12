class Solution {
private:
    const int INF = 1e9;
    
    int solve(int level, int sum, int target, vector<int>& nums, vector<vector<int>>& memo, const int& SHIFT){
        if(level == (int)nums.size()){
            return (sum == target);
        }else if(memo[level][sum + SHIFT] == INF){
            int addCount = solve(level + 1, sum - nums[level], target, nums, memo, SHIFT);
            int subtractCount = solve(level + 1, sum + nums[level], target, nums, memo, SHIFT);
            memo[level][sum + SHIFT] = min(addCount + subtractCount, INF);
        }
        return memo[level][sum + SHIFT];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> memo(N, vector<int>(2 * TOTAL_SUM + 1, INF));
        int res = solve(0, 0, target, nums, memo, TOTAL_SUM);
        if(res >= INF){
            res = 0;
        }
        
        return res;
    }
};