class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int maxLen = 0;

        int l = 0;
        long long wSum = 0;
        for(int r = 0; r < N; ++r){
            wSum += sortedNums[r];
            while((r - l + 1) * (long long)sortedNums[r] - wSum > k){
                wSum -= sortedNums[l];
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};