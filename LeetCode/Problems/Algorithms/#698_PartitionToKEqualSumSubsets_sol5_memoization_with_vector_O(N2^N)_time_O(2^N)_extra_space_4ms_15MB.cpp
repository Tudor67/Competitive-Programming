class Solution {
private:    
    bool solve(int k, int mask, int sum, const int& PARTITION_SUM, vector<int>& nums, vector<int>& memo){
        if(memo[mask] != -1){
            return memo[mask];
        }
        if(k == 1){
            memo[mask] = true;
            return true;
        }
        for(int bit = 0; bit < (int)nums.size(); ++bit){
            if(((mask >> bit) & 1) && (sum + nums[bit] <= PARTITION_SUM)){
                int nextSum = (sum + nums[bit]) % PARTITION_SUM;
                int nextMask = mask - (1 << bit);
                int nextK = k - (int)(nextSum == 0);
                if(solve(nextK, nextMask, nextSum, PARTITION_SUM, nums, memo)){
                    memo[mask] = true;
                    return true;
                }
            }
        }
        memo[mask] = false;
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int PARTITION_SUM = TOTAL_SUM / k;
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        if(PARTITION_SUM * k != TOTAL_SUM || PARTITION_SUM < MAX_NUM){
            return false;
        }
        
        vector<int> memo(FULL_MASK + 1, -1);
        bool isPossible = solve(k, FULL_MASK, 0, PARTITION_SUM, nums, memo);
        
        return isPossible;
    }
};