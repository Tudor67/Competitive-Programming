class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();

        long long validSubarrays = 0;
        long long wSum = 0;
        int l = 0;

        for(int r = 0; r < N; ++r){
            wSum += nums[r];
            while(wSum * (r - l + 1) >= k){
                wSum -= nums[l];
                l += 1;
            }
            validSubarrays += (r - l + 1);
        }

        return validSubarrays;
    }
};