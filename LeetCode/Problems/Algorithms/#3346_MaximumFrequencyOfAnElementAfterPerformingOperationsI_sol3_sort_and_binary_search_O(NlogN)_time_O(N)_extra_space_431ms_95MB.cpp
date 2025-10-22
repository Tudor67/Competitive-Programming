class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        for(int num: sortedNums){
            for(int target: {num - k, num, num + k}){
                int count0 = upper_bound(sortedNums.begin(), sortedNums.end(), target) -
                             lower_bound(sortedNums.begin(), sortedNums.end(), target);
                int count01 = upper_bound(sortedNums.begin(), sortedNums.end(), target + k) -
                              lower_bound(sortedNums.begin(), sortedNums.end(), target - k);
                res = max(res, count0 + min(count01 - count0, numOperations));
            }
        }

        return res;
    }
};