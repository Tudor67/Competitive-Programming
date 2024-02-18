class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int N = nums.size();

        int maxFreq = 0;
        vector<int> freq(N + 1);

        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[nums[r]] += 1;
            maxFreq = max(maxFreq, freq[nums[r]]);
            if(r - l + 1 - maxFreq > k){
                freq[nums[l]] -= 1;
                l += 1;
            }
        }

        return maxFreq;
    }
};