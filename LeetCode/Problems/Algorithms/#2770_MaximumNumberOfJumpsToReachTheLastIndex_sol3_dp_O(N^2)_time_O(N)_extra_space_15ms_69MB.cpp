class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int N = nums.size();

        // maxJumps[i]: max jumps to reach index (N - 1) from index i
        vector<int> maxJumps(N, -1);
        maxJumps[N - 1] = 0;

        for(int i = N - 2; i >= 0; --i){
            for(int j = i + 1; j < N; ++j){
                if(maxJumps[j] >= 0 && abs(nums[j] - nums[i]) <= target){
                    maxJumps[i] = max(maxJumps[i], 1 + maxJumps[j]);
                }
            }
        }

        return maxJumps[0];
    }
};