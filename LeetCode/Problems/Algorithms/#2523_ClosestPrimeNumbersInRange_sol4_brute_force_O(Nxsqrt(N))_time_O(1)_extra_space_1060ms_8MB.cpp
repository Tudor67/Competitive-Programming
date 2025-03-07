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
        array<int, 3> res = {INT_MAX, -1, -1};

        int prevPrime = -1;
        for(int i = left; i <= right; ++i){
            if(isPrime(i)){
                if(prevPrime >= 2){
                    res = min(res, {i - prevPrime, prevPrime, i});
                }
                prevPrime = i;
            }
        }

        return {res[1], res[2]};
    }
};