class Solution {
private:
    const int INF = 1e9;

    int computeMaxDiff(int l, int r, vector<int>& nums, vector<vector<int>>& memo){
        if(l > r){
            return 0;
        }
        
        if(memo[l][r] != INF){
            return memo[l][r];
        }
        
        int opt1 = nums[l] - computeMaxDiff(l + 1, r, nums, memo);
        int opt2 = nums[r] - computeMaxDiff(l, r - 1, nums, memo);
        int maxDiff = max(opt1, opt2);

        memo[l][r] = maxDiff;
        return maxDiff;
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return (computeMaxDiff(0, N - 1, nums, memo) >= 0);
    }
};