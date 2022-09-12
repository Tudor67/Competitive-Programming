class Solution {
private:
    const int INF = 2e9;
    
    int solve(int leftIdx, int rightIdx, vector<int>& nums, vector<vector<int>>& memo){
        if(leftIdx == rightIdx){
            return nums[rightIdx];
        }
        if(memo[leftIdx][rightIdx] == INF){
            int diff1 = nums[leftIdx] - solve(leftIdx + 1, rightIdx, nums, memo);
            int diff2 = nums[rightIdx] - solve(leftIdx, rightIdx - 1, nums, memo);
            memo[leftIdx][rightIdx] = max(diff1, diff2);
        }
        return memo[leftIdx][rightIdx];
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return (solve(0, N - 1, nums, memo) >= 0);
    }
};