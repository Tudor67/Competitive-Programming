class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int TARGET_SUM = TOTAL_SUM / 2;

        if(TOTAL_SUM % 2 == 1){
            return false;
        }

        // isPossible[s]: true, if it is possible to create a subset of nums with sum s
        //                false, otherwise
        vector<bool> isPossible(TARGET_SUM + 1, false);
        isPossible[0] = true;
        for(int num: nums){
            for(int sum = TARGET_SUM; sum >= num && !isPossible[TARGET_SUM]; --sum){
                if(isPossible[sum - num]){
                    isPossible[sum] = true;
                }
            }
        }

        return isPossible[TARGET_SUM];
    }
};