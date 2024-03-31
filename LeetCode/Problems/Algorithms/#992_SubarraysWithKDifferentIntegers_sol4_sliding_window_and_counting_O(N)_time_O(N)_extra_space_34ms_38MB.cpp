class Solution {
private:
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        const int N = nums.size();

        int subarraysCount = 0;
        vector<int> f(N + 1);
        int distinct = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            f[nums[r]] += 1;
            distinct += (int)(f[nums[r]] == 1);
            while(l <= r && distinct > k){
                distinct -= (int)(f[nums[l]] == 1);
                f[nums[l]] -= 1;
                l += 1;
            }
            subarraysCount += (r - l + 1);
        }

        return subarraysCount;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums, k) -
               countSubarraysWithAtMostKDistinct(nums, k - 1);
    }
};