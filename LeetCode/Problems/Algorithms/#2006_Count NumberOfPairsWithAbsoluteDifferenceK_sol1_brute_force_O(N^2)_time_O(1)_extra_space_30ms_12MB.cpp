class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int N = nums.size();
        int pairsCount = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(abs(nums[i] - nums[j]) == k){
                    pairsCount += 1;
                }
            }
        }
        return pairsCount;
    }
};