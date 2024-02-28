class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int MODULO, int K) {
        const int N = nums.size();

        long long res = 0;
        vector<int> f(N + 1);
        f[0] = 1;
        
        int prefCount = 0;
        for(int num: nums){
            prefCount += (int)(num % MODULO == K);
            prefCount %= MODULO;
            
            int targetPrefCount = (prefCount - K + MODULO) % MODULO;
            if(targetPrefCount <= N){
                res += f[targetPrefCount];
            }
            
            f[prefCount] += 1;
        }
        
        return res;
    }
};