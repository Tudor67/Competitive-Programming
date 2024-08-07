class Solution {
private:
    pair<long long, long long> computeCountAndWeightedSumOfValidSubarrays(vector<int>& nums,
                                                                          const long long MAX_SUM_THRESHOLD){
        const int N = nums.size();

        long long validSubarrays = 0;
        long long totalWeightedSum = 0;

        long long sum = 0;
        long long weightedSum = 0;
        for(long long i = 0, j = 0; j < N; ++j){
            sum += nums[j];
            weightedSum += (j - i + 1) * nums[j];
            while(sum > MAX_SUM_THRESHOLD){
                weightedSum -= sum;
                sum -= nums[i];
                i += 1;
            }
            validSubarrays += j - i + 1;
            totalWeightedSum += weightedSum;
        }

        return {validSubarrays, totalWeightedSum};
    }

    long long f(vector<int>& nums, int k){
        const int N = nums.size();

        long long l = 0;
        long long r = accumulate(nums.begin(), nums.end(), (long long)0);
        while(l != r){
            long long mid = (l + r) / 2;
            if(computeCountAndWeightedSumOfValidSubarrays(nums, mid).first < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        const long long MAX_SUM_THRESHOLD = r;
        pair<long long, long long> p = computeCountAndWeightedSumOfValidSubarrays(nums, MAX_SUM_THRESHOLD);
        long long subarraysCount = p.first;
        long long sum = p.second;

        return (sum - (subarraysCount - k) * MAX_SUM_THRESHOLD);
    }

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const long long MODULO = 1e9 + 7;
        return (f(nums, right) - f(nums, left - 1)) % MODULO;
    }
};