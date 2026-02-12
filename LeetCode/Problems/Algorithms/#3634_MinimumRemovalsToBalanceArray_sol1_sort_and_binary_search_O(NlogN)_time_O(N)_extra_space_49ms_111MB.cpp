class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int minCost = N - 1;
        for(int i = 0; i < N; ++i){
            int maxNum = sortedNums[i];
            int minNum = (maxNum + k - 1) / k;
            int minNumIndex = lower_bound(sortedNums.begin(), sortedNums.begin() + i, minNum) - sortedNums.begin();
            int currCost = minNumIndex + (N - 1 - i);
            minCost = min(minCost, currCost);
        }

        return minCost;
    }
};