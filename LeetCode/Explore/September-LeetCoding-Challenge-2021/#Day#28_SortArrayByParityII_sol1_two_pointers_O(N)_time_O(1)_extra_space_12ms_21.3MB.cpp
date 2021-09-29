class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        const int N = nums.size();
        int evenIdx = 0;
        int oddIdx = 1;
        while(evenIdx < N && oddIdx < N){
            if(nums[evenIdx] % 2 == 1 && nums[oddIdx] % 2 == 0){
                swap(nums[evenIdx], nums[oddIdx]);
                evenIdx += 2;
                oddIdx += 2;
            }else if(nums[evenIdx] % 2 == 0){
                evenIdx += 2;
            }else{
                oddIdx += 2;
            }
        }
        return nums;
    }
};