class Solution {
private:
    long long countPairsWithSumLessThanOrEqualTo(vector<int>& sortedNums, int sumLimit){
        long long pairs = 0;

        int l = 0;
        int r = (int)sortedNums.size() - 1;
        while(l < r){
            while(l < r && sortedNums[l] + sortedNums[r] > sumLimit){
                r -= 1;
            }
            pairs += (r - l);
            l += 1;
        }

        return pairs;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        return countPairsWithSumLessThanOrEqualTo(sortedNums, upper) -
               countPairsWithSumLessThanOrEqualTo(sortedNums, lower - 1);
    }
};