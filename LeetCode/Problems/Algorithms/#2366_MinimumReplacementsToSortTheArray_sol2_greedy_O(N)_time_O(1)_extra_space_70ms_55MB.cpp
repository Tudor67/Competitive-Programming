class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        const int N = nums.size();

        long long totalOps = 0;
        int limit = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            int k = (nums[i] + limit - 1) / limit;
            totalOps += k - 1;
            limit = min(limit, nums[i] / k);
        }

        return totalOps;
    }
};