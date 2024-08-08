class Solution {
private:
    bool isIncremovable(vector<int>& nums, int l, int r){
        const int N = nums.size();

        int prevNum = -1;
        for(int i = 0; i < N; ++i){
            if(!(l <= i && i <= r)){
                if(prevNum >= nums[i]){
                    return false;
                }
                prevNum = nums[i];
            }
        }

        return true;
    }

public:
    int incremovableSubarrayCount(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                if(isIncremovable(nums, i, j)){
                    res += 1;
                }
            }
        }

        return res;
    }
};