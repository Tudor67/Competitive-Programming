class Solution {
public:
    int concatenatedBinary(int n) {
        const int MODULO = 1e9 + 7;
        
        int res = 0;
        for(int num = 1; num <= n; ++num){
            for(int x = num; x >= 1; x >>= 1){
                res = (res * 2) % MODULO;
            }
            res = (res + num) % MODULO;
        }
        
        return res;
    }
};