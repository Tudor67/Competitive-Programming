class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();

        int maxLen = 0;

        unordered_map<int, int> f;
        int l = 0;
        for(int r = 0; r < N; ++r){
            f[nums[r]] += 1;
            while(f[nums[r]] > k){
                f[nums[l]] -= 1;
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};