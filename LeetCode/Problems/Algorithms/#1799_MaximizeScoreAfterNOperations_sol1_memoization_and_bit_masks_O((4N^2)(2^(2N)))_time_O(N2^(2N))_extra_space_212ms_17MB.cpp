class Solution {
private:
    int computeMaxScore(int step, int maskVisNums, vector<int>& nums, const int& N, vector<vector<int>>& memo){
        if(step == 0){
            return 0;
        }
        if(memo[step][maskVisNums] != -1){
            return memo[step][maskVisNums];
        }
        int maxScore = 0;
        for(int i = 0; i < 2 * N; ++i){
            for(int j = i + 1; j < 2 * N; ++j){
                if(!((maskVisNums >> i) & 1) && !((maskVisNums >> j) & 1)){
                    int score = step * gcd(nums[i], nums[j]) +
                                computeMaxScore(step - 1, maskVisNums ^ (1 << i) ^ (1 << j), nums, N, memo);
                    maxScore = max(maxScore, score);
                }
            }
        }
        memo[step][maskVisNums] = maxScore;
        return maxScore;
    }
    
public:
    int maxScore(vector<int>& nums) {
        const int N = nums.size() / 2;
        const int FULL_MASK = (1 << (2 * N)) - 1;
        vector<vector<int>> memo(N + 1, vector<int>(FULL_MASK + 1, -1));
        return computeMaxScore(N, 0, nums, N, memo);
    }
};