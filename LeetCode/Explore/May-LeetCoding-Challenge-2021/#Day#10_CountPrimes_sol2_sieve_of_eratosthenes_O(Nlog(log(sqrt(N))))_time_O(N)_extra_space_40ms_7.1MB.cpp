class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 2, true);
        for(int i = 2; i * i < n; ++i){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        int primesCount = 0;
        for(int i = 2; i < n; ++i){
            primesCount += isPrime[i];
        }
        return primesCount;
    }
};