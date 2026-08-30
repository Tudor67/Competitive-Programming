class Solution {
private:
    const int INF = INT_MAX;

    int f(int l, int r, vector<int>& nums, vector<vector<int>>& memo){
        if(l > r){
            return 0;
        }
        if(memo[l][r] == INF){
            memo[l][r] = max(nums[l] - f(l + 1, r, nums, memo),
                             nums[r] - f(l, r - 1, nums, memo));
        }
        return memo[l][r];
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return (f(0, N - 1, nums, memo) >= 0);
    }
};