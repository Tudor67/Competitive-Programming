class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        int i = 1;
        for(int j = 2; j < N; ++j){
            if(nums[i] - nums[i - 1] != nums[j] - nums[j - 1]){
                i = j;
            }
            res += (j - i);
        }
        
        return res;
    }
};