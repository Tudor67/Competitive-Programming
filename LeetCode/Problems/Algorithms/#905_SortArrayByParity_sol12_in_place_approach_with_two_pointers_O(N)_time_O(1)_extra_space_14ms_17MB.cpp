class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N - 1;
        while(l < r){
            if(nums[l] % 2 == 0){
                l += 1;
            }else if(nums[r] % 2 == 1){
                r -= 1;
            }else{
                swap(nums[l], nums[r]);
                l += 1;
                r -= 1;
            }
        }

        return nums;
    }
};