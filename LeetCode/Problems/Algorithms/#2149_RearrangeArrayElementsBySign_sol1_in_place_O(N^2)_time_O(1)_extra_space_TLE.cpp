class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N; ++i){
            if((i % 2 == 0 && nums[i] < 0) || (i % 2 == 1 && nums[i] >= 0)){
                int j = i + 1;
                while((nums[i] >= 0) == (nums[j] >= 0)){
                    ++j;
                }
                int tempNum = nums[j];
                copy_backward(nums.begin() + i, nums.begin() + j, nums.begin() + j + 1);
                nums[i] = tempNum;
            }
        }
        
        return nums;
    }
};