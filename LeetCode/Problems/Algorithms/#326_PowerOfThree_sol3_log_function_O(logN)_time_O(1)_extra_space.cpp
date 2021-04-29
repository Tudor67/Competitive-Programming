class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        long double x = log2((long double)n) / log2((long double)3);
        return ((long double)x == (int)x);
    }
};