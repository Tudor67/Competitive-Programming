class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        const int R = groups.size();
        const int N = nums.size();
        vector<int>::iterator it = nums.begin();
        for(int i = 0; i < R; ++i){
            it = search(it, nums.end(), groups[i].begin(), groups[i].end());
            if(it == nums.end()){
                return false;
            }else{
                advance(it, groups[i].size());
            }
        }
        return true;
    }
};