class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        for(int i = 1; i <= N; ++i){
            long long sum = 0;
            for(int j = 1; i * j * j <= N; ++j){
                sum += nums[i * j * j - 1];
            }
            res = max(res, sum);
        }

        return res;
    }
};