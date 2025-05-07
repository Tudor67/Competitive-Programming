class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int N = nums.size();
        const int SHIFT = 10;
        const int FULL_MASK = (1 << SHIFT) - 1;

        for(int i = 0; i < N; ++i){
            int val = (nums[nums[i]] & FULL_MASK);
            nums[i] |= (val << SHIFT);
        }

        for(int i = 0; i < N; ++i){
            nums[i] >>= SHIFT;
        }

        return nums;
    }
};