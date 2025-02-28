class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int N = nums.size();

        int maxAbsSum = 0;
        int minPrefSum = 0;
        int maxPrefSum = 0;
        int currPrefSum = 0;
        
        for(int i = 0; i < N; ++i){
            currPrefSum += nums[i];
            
            maxAbsSum = max(maxAbsSum, currPrefSum - minPrefSum);
            maxAbsSum = max(maxAbsSum, -(currPrefSum - maxPrefSum));

            minPrefSum = min(minPrefSum, currPrefSum);
            maxPrefSum = max(maxPrefSum, currPrefSum);
        }

        return maxAbsSum;
    }
};