class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        vector<int> maxLen(k);

        for(int rem = 0; rem < k; ++rem){
            fill(maxLen.begin(), maxLen.end(), 0);
            for(int num: nums){
                maxLen[num % k] = maxLen[(rem - num % k + k) % k] + 1;
                res = max(res, maxLen[num % k]);
            }
        }

        return res;
    }
};