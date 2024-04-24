class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const long long MODULO = 1e9 + 7;

        for(long long bit = n - 1; bit >= 0; --bit){
            long long aBit = (a >> bit) & 1;
            long long bBit = (b >> bit) & 1;
            if((aBit == 0 && bBit == 0) ||
               (aBit == 0 && bBit == 1 && b - a > (1LL << bit)) ||
               (aBit == 1 && bBit == 0 && a - b > (1LL << bit))){
                a ^= (1LL << bit);
                b ^= (1LL << bit);
            }
        }

        return (a % MODULO) * (b % MODULO) % MODULO;
    }
};