class Solution {
private:
    int solve(int len, int target, vector<int>& nums){
        if(len <= 0){
            return (target == 0);
        }
        if(target <= 0){
            return (target == 0);
        }
        int combinations = 0;
        for(int num: nums){
            combinations += solve(len - 1, target - num, nums);
        }
        return combinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(target, target, nums);
    }
};