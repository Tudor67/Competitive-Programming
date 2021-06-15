class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        vector<int> maxScore(N, -INF);
        maxScore[0] = nums[0];
        for(int i = 1; i < N; ++i){
            for(int j = max(0, i - k); j < i; ++j){
                maxScore[i] = max(nums[i] + maxScore[j], maxScore[i]);
            }
        }
        return maxScore[N - 1];
    }
};