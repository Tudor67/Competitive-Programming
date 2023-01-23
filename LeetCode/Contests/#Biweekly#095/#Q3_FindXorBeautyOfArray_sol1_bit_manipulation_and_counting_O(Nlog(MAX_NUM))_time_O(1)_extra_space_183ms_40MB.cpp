class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = floor(log2(MAX_NUM));
        
        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int ones = 0;
            for(int num: nums){
                if((num >> bit) & 1){
                    ones += 1;
                }
            }
            
            int parity = 0;
            int zeros = N - ones;
            for(int num: nums){
                if((num >> bit) & 1){
                    parity ^= ((ones * 1LL * N + zeros * 1LL * ones) & 1);
                }
            }
            
            if(parity == 1){
                res |= (1 << bit);
            }
        }
        
        return res;
    }
};