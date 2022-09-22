class Solution {
private:
    const int INF = 2e9 + 5;
    
    int solve(int l, int r, int multIdx, vector<int>& nums, vector<int>& multipliers, vector<int>& memo){
        const int M = multipliers.size();
        if(l > r || multIdx == M){
            return 0;
        }
        int state = l * M + multIdx;
        if(memo[state] == INF){
            int takeLeft = nums[l] * multipliers[multIdx] + solve(l + 1, r, multIdx + 1, nums, multipliers, memo);
            int takeRight = nums[r] * multipliers[multIdx] + solve(l, r - 1, multIdx + 1, nums, multipliers, memo);
            memo[state] = max(takeLeft, takeRight);
        }
        return memo[state];
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int N = nums.size();
        const int M = multipliers.size();
        vector<int> memo(M * M, INF);
        return solve(0, N - 1, 0, nums, multipliers, memo);
    }
};