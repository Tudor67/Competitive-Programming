class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        return max(sortedNums[0] * sortedNums[1] * sortedNums[N - 1],
                   sortedNums[N - 3] * sortedNums[N - 2] * sortedNums[N - 1]);
    }
};