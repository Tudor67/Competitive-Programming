class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << bit_width((unsigned int)N)) - 1;

        int maxK = FULL_MASK;
        for(int i = 0; i < N; ++i){
            if(nums[i] != i){
                maxK &= nums[i];
            }
        }

        if(maxK == FULL_MASK){
            maxK = 0;
        }

        return maxK;
    }
};