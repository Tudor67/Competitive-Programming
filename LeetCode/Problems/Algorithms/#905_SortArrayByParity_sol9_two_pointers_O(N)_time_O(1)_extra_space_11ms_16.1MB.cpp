class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();
        
        int i = 0;
        int j = N - 1;
        while(i < j){
            while(i < j && nums[i] % 2 == 0){
                i += 1;
            }
            while(i < j && nums[j] % 2 == 1){
                j -= 1;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
        }
        
        return nums;
    }
};