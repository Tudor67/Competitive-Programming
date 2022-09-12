class Solution {
private:
    void back(int level, int sum, int target, vector<int>& nums, int& res){
        if(level == (int)nums.size()){
            if(sum == target){
                res += 1;
            }
        }else{
            back(level + 1, sum - nums[level], target, nums, res);
            back(level + 1, sum + nums[level], target, nums, res);
        }
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        int res = 0;
        back(0, 0, target, nums, res);
        return res;
    }
};