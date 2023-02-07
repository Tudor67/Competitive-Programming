class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = floor(log2(MAX_NUM));
        const int FULL_MASK = (1 << (MAX_BIT + 1)) - 1;

        for(int i = 0; i < 2 * n; ++i){
            int targetIndex = 2 * i;
            if(i >= n){
                targetIndex = 2 * (i - n) + 1;
            }
            int originalNum = nums[i] & FULL_MASK;
            nums[targetIndex] = nums[targetIndex] | (originalNum << (MAX_BIT + 1));
        }

        for(int i = 0; i < 2 * n; ++i){
            nums[i] >>= (MAX_BIT + 1);
        }

        return nums;
    }
};