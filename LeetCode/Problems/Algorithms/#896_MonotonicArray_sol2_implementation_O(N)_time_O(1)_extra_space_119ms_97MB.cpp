class Solution {
private:
    bool isIncreasing(vector<int>& nums){
        const int N = nums.size();
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] > nums[i + 1]){
                return false;
            }
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums){
        const int N = nums.size();
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] < nums[i + 1]){
                return false;
            }
        }
        return true;
    }

public:
    bool isMonotonic(vector<int>& nums) {
        return isIncreasing(nums) || isDecreasing(nums);
    }
};