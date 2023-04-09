class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = nums[0];
        long long sum = nums[0];
        int count = 1;
        for(int i = 1; i < N; ++i){
            sum += nums[i];
            count += 1;
            res = max(res, (sum + count - 1) / count);
        }

        return res;
    }
};