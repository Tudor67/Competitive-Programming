class Solution {
public:
    int minPairSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int maxSum = sortedNums[0] + sortedNums[N - 1];
        for(int i = 1; i < N / 2; ++i){
            maxSum = max(maxSum, sortedNums[i] + sortedNums[N - 1 - i]);
        }

        return maxSum;
    }
};