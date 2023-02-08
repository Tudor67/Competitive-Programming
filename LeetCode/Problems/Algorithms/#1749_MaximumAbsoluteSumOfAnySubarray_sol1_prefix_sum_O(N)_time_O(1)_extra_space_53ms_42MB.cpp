class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int N = nums.size();

        int res = abs(nums[0]);
        int prefSum = 0;
        int minPrefSum = 0;
        int maxPrefSum = 0;
        
        for(int num: nums){
            prefSum += num;
            res = max(res, abs(prefSum - minPrefSum));
            res = max(res, abs(prefSum - maxPrefSum));
            minPrefSum = min(minPrefSum, prefSum);
            maxPrefSum = max(maxPrefSum, prefSum);
        }

        return res;
    }
};