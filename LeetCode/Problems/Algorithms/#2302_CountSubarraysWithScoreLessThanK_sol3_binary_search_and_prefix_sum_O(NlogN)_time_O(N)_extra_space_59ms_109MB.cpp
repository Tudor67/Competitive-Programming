class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return (prefSum[r] - prefSum[l - 1]);
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();

        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        long long validSubarrays = 0;
        for(int i = 0; i < N; ++i){
            long long l = 0;
            long long r = N - i;
            while(l != r){
                long long mid = (l + r + 1) / 2;
                if(getRangeSum(prefSum, i, i + mid - 1) * mid >= k){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
            validSubarrays += r;
        }

        return validSubarrays;
    }
};