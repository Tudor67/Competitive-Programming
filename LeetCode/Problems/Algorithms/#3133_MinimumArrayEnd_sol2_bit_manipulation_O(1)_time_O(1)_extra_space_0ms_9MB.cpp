class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;

        int bit = 0;
        for(int index = n - 1; index > 0; index >>= 1){
            while(x & 1){
                x >>= 1;
                bit += 1;
            }
            if(index & 1){
                res |= (1LL << bit);
            }
            x >>= 1;
            bit += 1;
        }

        return res;
    }
};