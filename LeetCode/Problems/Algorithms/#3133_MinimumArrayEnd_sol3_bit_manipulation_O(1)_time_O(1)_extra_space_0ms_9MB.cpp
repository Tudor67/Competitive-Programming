class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = 0;
        int index = n - 1;
        for(int bit = 0; bit <= 60; ++bit){
            if(((long long)x >> bit) & 1){
                res |= (1LL << bit);
            }else{
                if(index & 1){
                    res |= (1LL << bit);
                }
                index >>= 1;
            }
        }
        return res;
    }
};