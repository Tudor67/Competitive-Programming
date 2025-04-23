class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        const int N = nums.size();

        long long goodSubarrays = 0;
        long long wGoodPairs = 0;
        unordered_map<int, int> f;

        int l = 0;
        for(int r = 0; r < N; ++r){
            f[nums[r]] += 1;
            wGoodPairs += (f[nums[r]] - 1);
            
            while(wGoodPairs - (f[nums[l]] - 1) >= k){
                wGoodPairs -= (f[nums[l]] - 1);
                f[nums[l]] -= 1;
                l += 1;
            }

            if(wGoodPairs >= k){
                goodSubarrays += (l + 1);
            }
        }

        return goodSubarrays;
    }
};