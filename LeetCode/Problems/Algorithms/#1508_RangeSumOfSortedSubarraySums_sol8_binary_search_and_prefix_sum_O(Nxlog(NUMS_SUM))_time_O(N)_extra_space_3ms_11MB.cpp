class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }

    long long getRangeWeightedSum(vector<long long>& prefSum, vector<long long>& weightedPrefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return weightedPrefSum[r];
        }
        return weightedPrefSum[r] - weightedPrefSum[l - 1] - l * getRangeSum(prefSum, l, r);
    }

    pair<long long, long long> computeCountAndWeightedSumOfValidSubarrays(vector<long long>& prefSum,
                                                                          vector<long long>& weightedPrefSum,
                                                                          const long long MAX_SUM_THRESHOLD){
        const int N = prefSum.size();

        long long validSubarrays = 0;
        long long weightedSum = 0;
        for(int i = 0, j = 0; j < N; ++j){
            while(getRangeSum(prefSum, i, j) > MAX_SUM_THRESHOLD){
                i += 1;
            }
            validSubarrays += j - i + 1;
            weightedSum += getRangeWeightedSum(prefSum, weightedPrefSum, i, j);
        }

        return {validSubarrays, weightedSum};
    }

    long long f(vector<int>& nums, int k){
        const int N = nums.size();

        vector<long long> prefSum(N);
        vector<long long> weightedPrefSum(N);
        prefSum[0] = nums[0];
        weightedPrefSum[0] = nums[0];
        for(long long i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
            weightedPrefSum[i] = weightedPrefSum[i - 1] + (i + 1) * nums[i];
        }

        long long l = 0;
        long long r = getRangeSum(prefSum, 0, N - 1);
        while(l != r){
            long long mid = (l + r) / 2;
            if(computeCountAndWeightedSumOfValidSubarrays(prefSum, weightedPrefSum, mid).first < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        const long long MAX_SUM_THRESHOLD = r;
        pair<long long, long long> p = computeCountAndWeightedSumOfValidSubarrays(prefSum, weightedPrefSum, MAX_SUM_THRESHOLD);
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