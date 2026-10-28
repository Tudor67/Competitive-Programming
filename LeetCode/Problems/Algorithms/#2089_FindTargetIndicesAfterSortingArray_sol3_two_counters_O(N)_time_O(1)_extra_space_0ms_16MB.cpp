class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int targetFirstIndex = 0;
        int targetCount = 0;
        for(int num: nums){
            if(num < target){
                ++targetFirstIndex;
            }else if(num == target){
                ++targetCount;
            }
        }

        vector<int> targetIndices(targetCount);
        iota(targetIndices.begin(), targetIndices.end(), targetFirstIndex);
        
        return targetIndices;
    }
};