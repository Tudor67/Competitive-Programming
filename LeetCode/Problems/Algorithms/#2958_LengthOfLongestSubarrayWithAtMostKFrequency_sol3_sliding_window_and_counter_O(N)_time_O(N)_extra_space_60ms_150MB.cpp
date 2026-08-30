class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();

        int maxLen = 0;
        unordered_map<int, int> freq;
        for(int l = 0, r = 0; r < N; ++r){
            freq[nums[r]] += 1;
            while(freq[nums[r]] > k){
                freq[nums[l]] -= 1;
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};