class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        
        int startIdx = it1 - nums.begin();
        int targetCount = it2 - it1;
        
        vector<int> indices(targetCount);
        iota(indices.begin(), indices.end(), startIdx);
        
        return indices;
    }
};