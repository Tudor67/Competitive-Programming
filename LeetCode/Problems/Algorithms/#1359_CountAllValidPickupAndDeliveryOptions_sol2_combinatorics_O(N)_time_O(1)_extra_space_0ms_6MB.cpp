class Solution {
public:
    int countOrders(int n) {
        const long long MODULO = 1e9 + 7;

        long long res = 1;
        for(int i = 2; i <= n; ++i){
            res *= (2 * i - 1) * (2 * i) / 2;
            res %= MODULO;
        }
        
        return res;
    }
};