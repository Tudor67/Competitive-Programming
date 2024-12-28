class Solution {
private:
    void back(int sum, int i, vector<int>& nums, int target, int& targetSumWays){
        if(i < 0){
            if(sum == target){
                targetSumWays += 1;
            }
        }else{
            back(sum + nums[i], i - 1, nums, target, targetSumWays);
            back(sum - nums[i], i - 1, nums, target, targetSumWays);
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int targetSumWays = 0;
        back(0, (int)nums.size() - 1, nums, target, targetSumWays);
        return targetSumWays;
    }
};