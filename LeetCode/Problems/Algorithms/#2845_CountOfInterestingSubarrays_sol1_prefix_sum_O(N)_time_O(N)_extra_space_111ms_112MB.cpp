class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int MODULO, int K) {
        const int N = nums.size();
        
        vector<int> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = (int)(nums[i] % MODULO == K);
        }
        
        long long res = 0;
        vector<int> f(N + 1);
        f[0] = 1;
        
        int prefSum = 0;
        for(int elem: v){
            prefSum = (prefSum + elem) % MODULO;
            
            int targetPrefSum = (prefSum - K + MODULO) % MODULO;
            if(targetPrefSum <= N){
                res += f[targetPrefSum];
            }
            
            f[prefSum] += 1;
        }
        
        return res;
    }
};