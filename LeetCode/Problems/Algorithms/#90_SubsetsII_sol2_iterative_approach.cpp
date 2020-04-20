class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> solutions;
        solutions.push_back({});
        
        int start_pos = 0;
        int end_pos = 0;
        for(int i = 0; i < (int)nums.size(); ++i){
            start_pos = (i > 0 && nums[i - 1] == nums[i] ? end_pos : 0); 
            end_pos = solutions.size();
            for(int j = start_pos; j < end_pos; ++j){
                solutions.push_back(solutions[j]);
                solutions.back().push_back(nums[i]);
            }
        }
        
        return solutions;
    }
};