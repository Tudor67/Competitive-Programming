class Solution {
private:
    bool isNonDecreasing(const vector<int>& NUMS){
        for(int i = 0; i < (int)NUMS.size() - 1; ++i){
            if(NUMS[i] > NUMS[i + 1]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool checkPossibility(vector<int>& nums) {
        int isPossible = true;
        for(int i = 0; i < (int)nums.size() - 1; ++i){
            if(nums[i] > nums[i + 1]){
                isPossible = false;
                // 1st case
                int temp = nums[i];
                nums[i] = nums[i + 1];
                isPossible |= isNonDecreasing(nums);
                nums[i] = temp;
                // 2nd case
                temp = nums[i + 1];
                nums[i + 1] = nums[i];
                isPossible |= isNonDecreasing(nums);
                nums[i + 1] = temp;
                break;
            }
        }
        return isPossible;
    }
};