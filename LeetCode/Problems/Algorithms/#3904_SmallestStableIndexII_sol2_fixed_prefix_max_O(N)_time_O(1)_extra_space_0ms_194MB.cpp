class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int N = nums.size();

        int fixedIndex = 0;
        int fixedPrefMax = nums[0];
        int currPrefMax = nums[0];

        for(int i = 1; i < N; ++i){
            currPrefMax = max(currPrefMax, nums[i]);
            if(nums[i] < fixedPrefMax - k){
                fixedIndex = i + 1;
                fixedPrefMax = max(currPrefMax, nums[min(i + 1, N - 1)]);
            }
        }

        if(fixedIndex == N){
            fixedIndex = -1;
        }

        return fixedIndex;
    }
};