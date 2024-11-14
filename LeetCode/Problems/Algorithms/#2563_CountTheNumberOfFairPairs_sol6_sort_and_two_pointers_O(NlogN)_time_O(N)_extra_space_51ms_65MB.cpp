class Solution {
private:
    long long countPairsWithSumAtMost(vector<int> nums, int threshold){
        const int N = nums.size();

        sort(nums.begin(), nums.end());
        
        long long validPairs = 0;
        int r = N - 1;
        for(int l = 0; l < r; ++l){
            while(l < r && nums[l] + nums[r] > threshold){
                r -= 1;
            }
            validPairs += (r - l);
        }

        return validPairs;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return countPairsWithSumAtMost(nums, upper) -
               countPairsWithSumAtMost(nums, lower - 1);
    }
};