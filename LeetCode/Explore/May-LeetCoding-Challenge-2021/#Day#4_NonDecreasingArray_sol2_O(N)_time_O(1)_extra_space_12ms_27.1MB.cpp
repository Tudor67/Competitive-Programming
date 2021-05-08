class Solution {
private:
    bool isNonDecreasing(vector<int>& nums){
        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i - 1] > nums[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i - 1] > nums[i]){
                bool isPossible = false;
                int temp = nums[i - 1];
                nums[i - 1] = nums[i];
                isPossible |= isNonDecreasing(nums);
                nums[i - 1] = temp;
                temp = nums[i];
                nums[i] = nums[i - 1];
                isPossible |= isNonDecreasing(nums);
                nums[i] = temp;
                return isPossible;
            }
        }
        return true;
    }
};