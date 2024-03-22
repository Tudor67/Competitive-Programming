class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        const int MAX_BIT = 30;
        
        vector<int> f(MAX_BIT + 1);
        for(int num: nums){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    f[bit] += 1;
                }
            }
        }

        long long res = 0;
        for(int i = 0; i < k; ++i){
            long long x = 0;
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if(f[bit] >= 1){
                    x |= (1 << bit);
                    f[bit] -= 1;
                }
            }
            res = (res + x * x) % MODULO;
        }

        return res;
    }
};