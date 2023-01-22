class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int N = right;
        const int INF = 1e9;

        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= N; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= N; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int prime1 = -1;
        int prime2 = -1;
        int prevPrime = -1;
        for(int i = left; i <= right; ++i){
            if(isPrime[i]){
                if(prevPrime >= 2 && (prime1 == -1 || i - prevPrime < prime2 - prime1)){
                    prime1 = prevPrime;
                    prime2 = i;
                }
                prevPrime = i;
            }
        }
        
        return {prime1, prime2};
    }
};