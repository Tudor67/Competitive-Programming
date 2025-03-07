class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> minPrimeFor(right + 1, 0);
        vector<int> primes;

        for(int i = 2; i <= right; ++i){
            if(minPrimeFor[i] == 0){
                minPrimeFor[i] = i;
                primes.push_back(i);
            }
            for(int j = 0; j < (int)primes.size() && primes[j] <= minPrimeFor[i] && primes[j] * i <= right; ++j){
                minPrimeFor[primes[j] * i] = primes[j];
            }
        }

        array<int, 3> res = {INT_MAX, -1, -1};
        int prevPrime = -1;

        for(int prime: primes){
            if(left <= prime && prime <= right){
                if(prevPrime >= 2){
                    res = min(res, {prime - prevPrime, prevPrime, prime});
                }
                prevPrime = prime;
            }
        }

        return {res[1], res[2]};
    }
};