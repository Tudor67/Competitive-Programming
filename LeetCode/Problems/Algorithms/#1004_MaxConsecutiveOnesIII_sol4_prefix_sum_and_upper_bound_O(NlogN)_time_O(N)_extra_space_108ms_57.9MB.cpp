class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> zerosPrefixSum(N);
        zerosPrefixSum[0] = (nums[0] == 0);
        for(int i = 1; i < N; ++i){
            zerosPrefixSum[i] = zerosPrefixSum[i - 1] + (nums[i] == 0);
        }
        
        int maxLen = 0;
        for(int i = 0; i < N; ++i){
            int j = upper_bound(zerosPrefixSum.begin() + i, zerosPrefixSum.end(), zerosPrefixSum[i] - (nums[i] == 0) + k) - zerosPrefixSum.begin() - 1;
            int len = j - i + 1;
            maxLen = max(len, maxLen);
        }
        
        return maxLen;
    }
};