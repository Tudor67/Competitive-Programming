class Solution {
public:
    int countPrimes(int n) {
        vector<int> minPrime(n, 0);
        vector<int> primes;
        for(int i = 2; i < n; ++i){
            if(minPrime[i] == 0){
                minPrime[i] = i;
                primes.push_back(i);
            }
            for(int j = 0; j < (int)primes.size() && primes[j] <= minPrime[i] && primes[j] * i < n; ++j){
                minPrime[primes[j] * i] = primes[j];
            }
        }
        return (int)primes.size();
    }
};