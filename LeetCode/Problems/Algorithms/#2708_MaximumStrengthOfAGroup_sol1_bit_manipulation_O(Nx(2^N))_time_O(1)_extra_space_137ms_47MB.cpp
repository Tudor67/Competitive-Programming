class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        
        long long maxProd = nums[0];
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            long long prod = 1;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    prod *= nums[bit];
                }
            }
            maxProd = max(maxProd, prod);
        }
        
        return maxProd;
    }
};