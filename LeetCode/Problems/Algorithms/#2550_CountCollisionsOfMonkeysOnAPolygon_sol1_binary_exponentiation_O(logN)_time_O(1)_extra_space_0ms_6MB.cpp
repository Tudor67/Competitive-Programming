class Solution {
private:
    long long binaryExponentiation(long long a, long long n, const long long& MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n /= 2;
        }
        return res;
    }

public:
    int monkeyMove(int n) {
        const long long MODULO = 1e9 + 7;
        long long totalWays = binaryExponentiation(2, n, MODULO);
        long long noCollisionWays = 2;
        long long collisionWays = (totalWays - noCollisionWays + MODULO) % MODULO;
        return collisionWays;
    }
};