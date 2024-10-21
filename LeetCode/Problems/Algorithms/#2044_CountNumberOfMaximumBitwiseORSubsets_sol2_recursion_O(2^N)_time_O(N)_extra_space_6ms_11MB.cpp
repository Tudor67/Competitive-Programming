class Solution {
private:
    void rec(int i, int currOR, int maxOR, vector<int>& nums, int& maxSubsets){
        if(i == (int)nums.size()){
            if(currOR == maxOR){
                maxSubsets += 1;
            }
        }else{
            rec(i + 1, currOR, maxOR, nums, maxSubsets);
            rec(i + 1, currOR | nums[i], maxOR, nums, maxSubsets);
        }
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int num: nums){
            maxOR |= num;
        }

        int maxSubsets = 0;
        rec(0, 0, maxOR, nums, maxSubsets);

        return maxSubsets;
    }
};