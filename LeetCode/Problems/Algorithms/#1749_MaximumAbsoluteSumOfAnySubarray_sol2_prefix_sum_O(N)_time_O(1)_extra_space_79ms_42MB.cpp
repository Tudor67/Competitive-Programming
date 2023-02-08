class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int N = nums.size();

        int prefSum = 0;
        int minPrefSum = 0;
        int maxPrefSum = 0;
        for(int num: nums){
            prefSum += num;
            minPrefSum = min(minPrefSum, prefSum);
            maxPrefSum = max(maxPrefSum, prefSum);
        }

        return maxPrefSum - minPrefSum;
    }
};