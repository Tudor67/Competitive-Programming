class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += upper_bound(sortedNums.begin() + i + 1, sortedNums.end(), upper - sortedNums[i]) -
                   lower_bound(sortedNums.begin() + i + 1, sortedNums.end(), lower - sortedNums[i]);
        }
        
        return res;
    }
};