class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const int N = nums.size();

        bool isIncreasing = true;
        bool isDecreasing = true;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] < nums[i + 1]){
                isDecreasing = false;
            }else if(nums[i] > nums[i + 1]){
                isIncreasing = false;
            }
        }

        return isIncreasing || isDecreasing;
    }
};