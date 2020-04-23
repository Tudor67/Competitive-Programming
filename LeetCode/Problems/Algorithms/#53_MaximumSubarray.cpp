class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_sol = nums[0];
        int cur_sol = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            cur_sol = max(cur_sol + nums[i], nums[i]);
            global_sol = max(cur_sol, global_sol);
        }
        
        return global_sol;
    }
};