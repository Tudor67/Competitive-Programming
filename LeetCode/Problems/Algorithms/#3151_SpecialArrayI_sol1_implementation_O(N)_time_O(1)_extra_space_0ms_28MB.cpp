class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] % 2 == nums[i + 1] % 2){
                return false;
            }
        }
        return true;
    }
};