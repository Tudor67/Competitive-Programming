class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int N = nums.size();

        int prefixMax = nums[0];
        vector<int> prefixGCD(N);
        for(int i = 0; i < N; ++i){
            prefixMax = max(prefixMax, nums[i]);
            prefixGCD[i] = gcd(prefixMax, nums[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        long long res = 0;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            res += gcd(prefixGCD[i], prefixGCD[j]);
        }
        
        return res;
    }
};