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
    vector<int> closestPrimes(int left, int right) {
        int resDiff = INT_MAX;
        int resPrime1 = -1;
        int resPrime2 = -1;

        int prevPrime = -1;
        for(int i = left; i <= right; ++i){
            if(isPrime(i)){
                if(prevPrime >= 2){
                    int diff = i - prevPrime;
                    if(resDiff > diff){
                        resDiff = diff;
                        resPrime1 = prevPrime;
                        resPrime2 = i;
                    }
                }
                prevPrime = i;
            }
        }

        return {resPrime1, resPrime2};
    }
};