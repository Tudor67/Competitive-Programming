class Solution {
private:
    long long countPairsWithSumAtMost(vector<int> nums, int threshold){
        const int N = nums.size();

        sort(nums.begin(), nums.end());
        
        long long validPairs = 0;
        for(int i = 0; i < N; ++i){
            int j = upper_bound(nums.begin() + i + 1, nums.end(), threshold - nums[i]) - nums.begin() - 1;
            validPairs += (j - i);
        }

        return validPairs;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return countPairsWithSumAtMost(nums, upper) -
               countPairsWithSumAtMost(nums, lower - 1);
    }
};