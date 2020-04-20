class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutions;
        
        int n = nums.size();
        long long full_mask = (1LL << n) - 1;
        for(long long mask = 0; mask <= full_mask; ++mask){
            vector<int> sol;
            for(int j = 0; j < n; ++j){
                if(mask & (1LL << j)){
                    sol.push_back(nums[j]);
                }
            }
            solutions.push_back(sol);
        }
        
        return solutions;
    }
};