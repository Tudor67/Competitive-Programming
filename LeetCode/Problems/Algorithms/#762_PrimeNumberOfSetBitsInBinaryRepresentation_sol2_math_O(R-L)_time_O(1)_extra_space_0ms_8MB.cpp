class Solution {
private:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(unsigned int num = left; num <= right; ++num){
            if(isPrime(popcount(num))){
                res += 1;
            }
        }
        return res;
    }
};