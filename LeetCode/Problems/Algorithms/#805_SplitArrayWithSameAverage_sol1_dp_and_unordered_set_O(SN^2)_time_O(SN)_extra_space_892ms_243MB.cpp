class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        const int N = nums.size();        
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int ZEROS = count(nums.begin(), nums.end(), 0);
        
        // dp[s]: true, if there is a subset of nums with sum s
        //        false, otherwise
        // sizes[s]: sizes of subsets with sum s
        vector<bool> dp(TOTAL_SUM + 1, false);
        vector<unordered_set<int>> sizes(TOTAL_SUM + 1);
        
        dp[0] = true;
        sizes[0].insert(0);
        for(int z = 1; z <= ZEROS; ++z){
            sizes[0].insert(z);
        }
        
        for(int num: nums){
            if(num == 0){
                continue;
            }
            for(int sum = TOTAL_SUM; sum >= num; --sum){
                if(dp[sum - num]){
                    dp[sum] = true;
                    for(int prevSize: sizes[sum - num]){
                        sizes[sum].insert(prevSize + 1);
                    }
                }
            }
        }
        
        for(int sum = 0; sum <= TOTAL_SUM; ++sum){
            if(!dp[sum]){
                continue;
            }
            for(int size: sizes[sum]){
                int sum1 = sum;
                int size1 = size;
                int sum2 = TOTAL_SUM - sum1;
                int size2 = N - size;
                if(size1 > 0 && size2 > 0){
                    if(sum1 * size2 == sum2 * size1){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};