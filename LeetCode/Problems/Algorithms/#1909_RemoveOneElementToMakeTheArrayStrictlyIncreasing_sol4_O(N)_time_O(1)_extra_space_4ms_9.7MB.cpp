class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int N = nums.size();
        
        int badIdx = 0;
        int badIdxCount = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] >= nums[i + 1]){
                badIdx = i;
                badIdxCount += 1;
            }
        }
        
        if(badIdxCount == 0){
            return true;
        }
        
        if(badIdxCount == 1){
            if(badIdx == 0 || badIdx == N - 2){
                return true;
            }
            if(nums[badIdx - 1] < nums[badIdx + 1] || nums[badIdx] < nums[badIdx + 2]){
                return true;
            }
        }
        
        return false;
    }
};