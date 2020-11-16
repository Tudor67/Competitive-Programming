class Solution {
private:
    void back(const vector<int>& NUMS, int level, vector<int>& st, vector<bool>& vis, bool checkUnique,
              vector<vector<int>>& permutations){
        if(level == st.size()){
            permutations.push_back({});
            for(int k = 0; k < st.size(); ++k){
                permutations.back().push_back(NUMS[st[k]]);
            }
        }else{
            for(int i = 0; i < st.size(); ++i){
                if(!vis[i]){
                    bool isUnique = (checkUnique ? NUMS[i] != NUMS[st[level]] : true);
                    if(isUnique){
                        vis[i] = true;
                        st[level] = i;
                        back(NUMS, level + 1, st, vis, false, permutations);
                        vis[i] = false;
                        checkUnique = true;
                    }
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int N = nums.size();
        // Step 1: sort
        sort(nums.begin(), nums.end());
        // Step 2: backtrack
        vector<int> st(N, -1);
        vector<bool> vis(N, false);
        vector<vector<int>> permutations;
        back(nums, 0, st, vis, false, permutations);
        return permutations;
    }
};