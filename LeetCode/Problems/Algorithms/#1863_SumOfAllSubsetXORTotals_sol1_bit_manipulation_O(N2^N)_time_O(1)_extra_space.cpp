class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        
        int sum = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int maskXOR = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    maskXOR ^= nums[bit];
                }
            }
            sum += maskXOR;
        }
        
        return sum;
    }
};