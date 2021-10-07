class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        const int N = nums.size();        
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int ZEROS = count(nums.begin(), nums.end(), 0);
        
        // dp[s]: true, if there is a subset of nums with sum s
        //        false, otherwise
        // sizeMasks[s]: sizes of subsets with sum s
        //               if kth bit of sizesMasks[s] is 1 => there is a subset of size k with sum of elements equal to s
        vector<bool> dp(TOTAL_SUM + 1, false);
        vector<int> sizeMasks(TOTAL_SUM + 1);
        
        dp[0] = true;
        sizeMasks[0] |= 1;
        for(int z = 1; z <= ZEROS; ++z){
            sizeMasks[0] |= (1 << z);
        }
        
        for(int num: nums){
            if(num == 0){
                continue;
            }
            for(int sum = TOTAL_SUM; sum >= num; --sum){
                if(dp[sum - num]){
                    dp[sum] = true;
                    sizeMasks[sum] |= (sizeMasks[sum - num] << 1);
                }
            }
        }
        
        for(int sum = 0; sum <= TOTAL_SUM; ++sum){
            if(!dp[sum]){
                continue;
            }
            for(int size = 1; size <= N - 1; ++size){
                if((sizeMasks[sum] >> size) & 1){
                    int sum1 = sum;
                    int size1 = size;
                    int sum2 = TOTAL_SUM - sum1;
                    int size2 = N - size;
                    if(sum1 * size2 == sum2 * size1){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};