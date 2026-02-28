class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        static const unordered_set<int> PRIMES_SET = {2, 3, 5, 7, 11, 13, 17, 19};

        int res = 0;
        for(unsigned int num = left; num <= right; ++num){
            if(PRIMES_SET.contains(popcount(num))){
                res += 1;
            }
        }
        
        return res;
    }
};