class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int N = nums.size();
        const long long NUMS_SUM = accumulate(nums.begin(), nums.end(), (long long)0);

        vector<long long> xorContribs(N);
        for(int i = 0; i < N; ++i){
            xorContribs[i] = (nums[i] ^ k) - nums[i];
        }

        sort(xorContribs.begin(), xorContribs.end());

        long long res = NUMS_SUM;
        for(int i = N - 1; i - 1 >= 0; i -= 2){
            res += max((long long)0, xorContribs[i - 1] + xorContribs[i]);
        }

        return res;
    }
};