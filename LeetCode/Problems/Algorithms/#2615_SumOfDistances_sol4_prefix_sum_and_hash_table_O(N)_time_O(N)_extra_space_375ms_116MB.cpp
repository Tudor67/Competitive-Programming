class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const long long N = nums.size();

        vector<long long> res(N);

        // compute contrib by moving from left to right
        unordered_map<int, long long> sum;
        unordered_map<int, long long> count;
        for(int i = 0; i < N; ++i){
            res[i] += (i * count[nums[i]] - sum[nums[i]]);
            sum[nums[i]] += i;
            count[nums[i]] += 1;
        }

        // compute contrib by moving from right to left
        sum.clear();
        count.clear();
        for(int i = N - 1; i >= 0; --i){
            res[i] += (sum[nums[i]] - i * count[nums[i]]);
            sum[nums[i]] += i;
            count[nums[i]] += 1;
        }

        return res;
    }
};