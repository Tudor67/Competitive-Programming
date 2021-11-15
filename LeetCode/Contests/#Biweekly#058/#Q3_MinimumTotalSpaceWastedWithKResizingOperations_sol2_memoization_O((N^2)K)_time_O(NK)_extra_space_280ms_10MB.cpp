class Solution {
private:
    const int INF = 1e8;
    
    int solve(int j, int k, vector<int>& nums, vector<vector<int>>& memo){
        if(memo[j][k] != INF){
            return memo[j][k];
        }
        int prefMax = *max_element(nums.begin(), nums.begin() + j + 1);
        int prefSum = accumulate(nums.begin(), nums.begin() + j + 1, 0);
        int minCost = (j + 1) * prefMax - prefSum;
        int suffMax = nums[j];
        int suffSum = nums[j];
        for(int i = j - 1; i >= 0 && k >= 1; --i){
            int cost = solve(i, k - 1, nums, memo) + (j - i) * suffMax - suffSum;
            minCost = min(minCost, cost);
            suffMax = max(suffMax, nums[i]);
            suffSum += nums[i];
        }
        memo[j][k] = minCost;
        return minCost;
    }
    
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<vector<int>> memo(N, vector<int>(k + 1, INF));
        return solve(N - 1, k, nums, memo);
    }
};