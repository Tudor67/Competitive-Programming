class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int BASE = MAX_NUM + 1;

        for(int i = 0; i < n; ++i){
            nums[i] = nums[i] * BASE + nums[i + n];
        }

        for(int i = n - 1; i >= 0; --i){
            nums[2 * i + 1] = nums[i] % BASE;
            nums[2 * i] = nums[i] / BASE;
        }

        return nums;
    }
};