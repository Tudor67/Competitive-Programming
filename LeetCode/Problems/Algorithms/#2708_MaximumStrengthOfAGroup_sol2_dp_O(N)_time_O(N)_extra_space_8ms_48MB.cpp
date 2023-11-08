class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int N = nums.size();
        
        // dpMin[i]: min product of a group from nums[0 .. i]
        // dpMax[i]: max product of a group from nums[0 .. i]
        vector<long long> dpMin(N);
        vector<long long> dpMax(N);
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];

        for(int i = 1; i < N; ++i){
            dpMin[i] = min({dpMin[i - 1], dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], 1LL * nums[i]});
            dpMax[i] = max({dpMax[i - 1], dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], 1LL * nums[i]});
        }

        return dpMax[N - 1];
    }
};