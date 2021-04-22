class Solution {
private:
    int solve(int target, vector<int>& nums){
        if(target <= 0){
            return (target == 0);
        }
        int combinations = 0;
        for(int num: nums){
            combinations += solve(target - num, nums);
        }
        return combinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(target, nums);
    }
};