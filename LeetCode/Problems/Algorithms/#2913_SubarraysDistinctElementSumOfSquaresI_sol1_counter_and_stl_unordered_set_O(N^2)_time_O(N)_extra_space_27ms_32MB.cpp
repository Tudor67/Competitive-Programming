class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        unordered_set<int> vis;
        
        for(int i = 0; i < N; ++i){
            vis.clear();
            for(int j = i; j < N; ++j){
                vis.insert(nums[j]);
                res += vis.size() * vis.size();
            }
        }

        return res;
    }
};