class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        unordered_map<int, int> maxLen;

        for(int rem = 0; rem < k; ++rem){
            maxLen.clear();
            for(int num: nums){
                maxLen[num % k] = maxLen[(rem - num % k + k) % k] + 1;
                res = max(res, maxLen[num % k]);
            }
        }

        return res;
    }
};