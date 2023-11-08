class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int N = nums.size();
        
        // At ith step:
        //    dpMin: min product of a group from nums[0 .. i]
        //    dpMax: max product of a group from nums[0 .. i]
        long long dpMin = nums[0];
        long long dpMax = nums[0];

        for(int i = 1; i < N; ++i){
            long long nextDPMin = min({dpMin, dpMin * nums[i], dpMax * nums[i], 1LL * nums[i]});
            long long nextDPMax = max({dpMax, dpMin * nums[i], dpMax * nums[i], 1LL * nums[i]});
            dpMin = nextDPMin;
            dpMax = nextDPMax;
        }

        return dpMax;
    }
};