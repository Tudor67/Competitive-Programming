class Solution {
private:
    int countSubarrays(vector<int>& nums, const int& MAXIMUM){
        int validSubarrays = 0;
        int consecutiveValidNums = 0;
        for(int num: nums){
            if(num <= MAXIMUM){
                consecutiveValidNums += 1;
            }else{
                consecutiveValidNums = 0;
            }
            validSubarrays += consecutiveValidNums;
        }
        return validSubarrays;
    }
    
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};