class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return -1;
        }

        int min3 = *min_element(nums.begin(), nums.begin() + 3);
        int max3 = *max_element(nums.begin(), nums.begin() + 3);
        for(int i = 0; i < 3; ++i){
            if(nums[i] != min3 && nums[i] != max3){
                return nums[i];
            }
        }

        return -1;
    }
};