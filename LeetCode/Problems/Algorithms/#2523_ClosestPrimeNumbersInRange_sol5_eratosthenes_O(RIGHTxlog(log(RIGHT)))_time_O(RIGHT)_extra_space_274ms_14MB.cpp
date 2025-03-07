class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i <= right; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= right; j += i){
                    isPrime[j] = false;
                }
            }
        }

        array<int, 3> res = {INT_MAX, -1, -1};
        int prevPrime = -1;
        for(int i = left; i <= right; ++i){
            if(isPrime[i]){
                if(prevPrime >= 2){
                    res = min(res, {i - prevPrime, prevPrime, i});
                }
                prevPrime = i;
            }
        }

        return {res[1], res[2]};
    }
};