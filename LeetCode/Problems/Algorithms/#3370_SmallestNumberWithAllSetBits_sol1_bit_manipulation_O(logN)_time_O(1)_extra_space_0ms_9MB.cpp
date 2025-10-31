class Solution {
public:
    int smallestNumber(int n) {
        int res = 0;
        for(int bit = 0; (1 << bit) <= n; ++bit){
            res |= (1 << bit);
        }
        return res;
    }
};