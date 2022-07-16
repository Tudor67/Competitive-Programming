class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();
        
        long long res = 0;
        long long sum = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            sum += nums[j];
            while(sum * (j - i + 1) >= k){
                sum -= nums[i];
                i += 1;
            }
            res += (j - i + 1);
        }
        
        return res;
    }
};