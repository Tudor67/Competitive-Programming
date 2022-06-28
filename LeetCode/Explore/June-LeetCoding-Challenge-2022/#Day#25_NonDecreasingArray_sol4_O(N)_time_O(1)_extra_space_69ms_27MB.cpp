class Solution {
private:
    bool isNonDecreasing(vector<int>& nums, int specialIdx, int specialVal){
        const int N = nums.size();
        
        for(int i = 0; i + 1 < N; ++i){
            int currentNum = (i == specialIdx ? specialVal : nums[i]);
            int nextNum = (i + 1 == specialIdx ? specialVal : nums[i + 1]);
            if(currentNum > nextNum){
                return false;
            }
        }
        
        return true;
    }
    
public:
    bool checkPossibility(vector<int>& nums) {
        const int N = nums.size();
        
        int badIdx = -1;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] > nums[i + 1]){
                badIdx = i;
                break;
            }
        }
        
        return badIdx == -1 ||
               isNonDecreasing(nums, badIdx, nums[badIdx + 1]) ||
               isNonDecreasing(nums, badIdx + 1, nums[badIdx]);
    }
};