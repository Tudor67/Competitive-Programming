class Solution {
private:
    void back(int startPos, vector<int>& st, vector<int>& nums, vector<vector<int>>& subsets){
        subsets.push_back(st);
        for(int i = startPos; i < (int)nums.size(); ++i){
            if(i > startPos && nums[i - 1] == nums[i]){
                // avoid duplicates
                continue;
            }
            st.push_back(nums[i]);
            back(i + 1, st, nums, subsets);
            st.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> st;
        vector<vector<int>> subsets;
        back(0, st, nums, subsets);
        
        return subsets;
    }
};