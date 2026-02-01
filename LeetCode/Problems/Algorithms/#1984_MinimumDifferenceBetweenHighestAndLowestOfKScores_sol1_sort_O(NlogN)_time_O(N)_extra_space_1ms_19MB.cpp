class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int minDiff = sortedNums[k - 1] - sortedNums[0];
        for(int i = 1; i + k - 1 < N; ++i){
            minDiff = min(minDiff, sortedNums[i + k - 1] - sortedNums[i]);
        }

        return minDiff;
    }
};