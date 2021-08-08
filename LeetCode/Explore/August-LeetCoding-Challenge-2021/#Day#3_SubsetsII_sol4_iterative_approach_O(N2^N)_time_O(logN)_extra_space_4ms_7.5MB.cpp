class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subsets = {{}};
        int startIdx = 0;
        int endIdx = 1;
        for(int i = 0; i < N; ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                // avoid duplicates
                startIdx = endIdx;
            }else{
                startIdx = 0;
            }
            endIdx = subsets.size();
            for(int j = startIdx; j < endIdx; ++j){
                subsets.push_back(subsets[j]);
                subsets.back().push_back(nums[i]);
            }
        }
        
        return subsets;
    }
};