class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int N = right;

        vector<bool> isPrime(N + 1, true);
        vector<int> primes;
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= N; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= N; j += i){
                    isPrime[j] = false;
                }
            }
            if(isPrime[i] && left <= i && i <= right){
                primes.push_back(i);
            }
        }

        int prime1 = -1;
        int prime2 = -1;
        for(int i = 1; i < (int)primes.size(); ++i){
            if(prime1 == -1 || primes[i] - primes[i - 1] < prime2 - prime1){
                prime1 = primes[i - 1];
                prime2 = primes[i];
            }
        }
        
        return {prime1, prime2};
    }
};