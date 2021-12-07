class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int lessCount = 0;
        int targetCount = 0;
        for(int num: nums){
            if(num < target){
                ++lessCount;
            }else if(num == target){
                ++targetCount;
            }
        }
        
        vector<int> indices(targetCount);
        iota(indices.begin(), indices.end(), lessCount);
        
        return indices;
    }
};