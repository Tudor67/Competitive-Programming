class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        
        if(n == 1){
            return true;
        }
        
        int nonZeroBits = __builtin_popcount((unsigned int)n);
        int trailingZeros = __builtin_ctz((unsigned int)n);
        return (nonZeroBits == 1 && trailingZeros % 2 == 0);
    }
};