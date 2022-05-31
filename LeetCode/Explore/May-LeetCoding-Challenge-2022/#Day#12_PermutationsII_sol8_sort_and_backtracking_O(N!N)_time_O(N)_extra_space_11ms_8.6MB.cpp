class Solution {
private:
    void back(int level, vector<int>& st, vector<bool>& vis, bool& updatedPrefix, vector<int>& nums, vector<vector<int>>& res){
        if(level == (int)nums.size()){
            res.push_back(st);
        }else{
            for(int i = 0; i < (int)nums.size(); ++i){
                if(vis[i]){
                    continue;
                }
                if(!updatedPrefix){
                    if(st[level] == nums[i]){
                        continue;
                    }
                }
                st[level] = nums[i];
                vis[i] = true;
                updatedPrefix = true;
                back(level + 1, st, vis, updatedPrefix, nums, res);
                updatedPrefix = false;
                vis[i] = false;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> st(N);
        vector<bool> vis(N, false);
        bool updatedPrefix = true;
        vector<vector<int>> res;
        back(0, st, vis, updatedPrefix, nums, res);
        
        return res;
    }
};