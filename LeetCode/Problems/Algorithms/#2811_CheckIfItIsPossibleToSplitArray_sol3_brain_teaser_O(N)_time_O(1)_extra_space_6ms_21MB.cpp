class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        const int N = nums.size();

        int maxAdjSum = 0;
        for(int i = 0; i + 1 < N; ++i){
            maxAdjSum = max(maxAdjSum, nums[i] + nums[i + 1]);
        }

        return (N <= 2 || maxAdjSum >= m);
    }
};