class Solution {
private:
    void back(int startPos, vector<int>& st, vector<int>& nums, set<vector<int>>& incSubsequencesSet){
        if((int)st.size() >= 2){
            incSubsequencesSet.insert(st);
        }
        for(int pos = startPos; pos < (int)nums.size(); ++pos){
            if(pos > startPos && nums[pos - 1] == nums[pos]){
                // avoid some of the duplicates
                // (remember that nums is not sorted)
                continue;
            }
            if(st.empty() || st.back() <= nums[pos]){
                st.push_back(nums[pos]);
                back(pos + 1, st, nums, incSubsequencesSet);
                st.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> st;
        set<vector<int>> incSubsequencesSet;
        back(0, st, nums, incSubsequencesSet);
        vector<vector<int>> incSubsequences(incSubsequencesSet.begin(), incSubsequencesSet.end());
        return incSubsequences;
    }
};