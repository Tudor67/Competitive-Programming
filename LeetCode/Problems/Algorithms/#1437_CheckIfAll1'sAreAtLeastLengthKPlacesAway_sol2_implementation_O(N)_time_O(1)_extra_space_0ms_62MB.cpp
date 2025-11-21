class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        const int N = nums.size();

        int prevIndexOfOne = -1;
        for(int i = 0; i < N; ++i){
            if(nums[i] == 1){
                if(prevIndexOfOne >= 0 && i - prevIndexOfOne - 1 < k){
                    return false;
                }
                prevIndexOfOne = i;
            }
        }

        return true;
    }
};