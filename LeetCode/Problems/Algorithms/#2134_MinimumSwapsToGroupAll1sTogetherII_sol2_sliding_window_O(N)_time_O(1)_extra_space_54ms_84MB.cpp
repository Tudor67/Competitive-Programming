class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int N = nums.size();
        const int TARGET_ONES = count(nums.begin(), nums.end(), 1);

        int minOps = N;
        int wOnes = 0;
        for(int i = 0; i < 2 * N; ++i){
            wOnes += nums[i % N];
            if(i >= TARGET_ONES){
                wOnes -= nums[(i - TARGET_ONES) % N];
            }
            if(i >= TARGET_ONES - 1){
                minOps = min(minOps, TARGET_ONES - wOnes);
            }
        }

        return minOps;
    }
};