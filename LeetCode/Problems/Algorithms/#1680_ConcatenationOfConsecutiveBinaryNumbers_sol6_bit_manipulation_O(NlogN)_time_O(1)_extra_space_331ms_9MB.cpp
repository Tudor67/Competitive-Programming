class Solution {
public:
    int concatenatedBinary(int n) {
        const int MODULO = 1'000'000'007;

        int res = 0;
        for(int i = 1; i <= n; ++i){
            int msb = floor(log2(i));
            for(int bit = msb; bit >= 0; --bit){
                if((i >> bit) & 1){
                    res = (res * 2 + 1) % MODULO;
                }else{
                    res = (res * 2) % MODULO;
                }
            }
        }

        return res;
    }
};