class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();
        
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] >= k){
                continue;
            }
            int l = i;
            int r = N - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                long long rangeSum = getRangeSum(prefSum, i, mid);
                long long rangeSize = mid - i + 1;
                if(rangeSum * rangeSize < k){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            res += (r - i + 1);
        }
        
        return res;
    }
};