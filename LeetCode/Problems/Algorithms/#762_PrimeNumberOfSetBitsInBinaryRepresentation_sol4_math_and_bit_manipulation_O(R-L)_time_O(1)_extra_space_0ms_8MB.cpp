class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        static const int PRIMES_MASK = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
                                       (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);

        int res = 0;
        for(unsigned int num = left; num <= right; ++num){
            if(PRIMES_MASK & (1 << popcount(num))){
                res += 1;
            }
        }
        
        return res;
    }
};