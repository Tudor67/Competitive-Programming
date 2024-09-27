class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // dp[num]: max length of a resulting subarray of consecutive values ending with num
        map<int, int> dp;
        int maxLen = 0;
        for(int num: sortedNums){
            dp[num + 1] = max(dp[num + 1], dp[num] + 1);
            dp[num] = max(dp[num], dp[num - 1] + 1);
            maxLen = max(maxLen, max(dp[num], dp[num + 1]));
        }

        return maxLen;
    }
};