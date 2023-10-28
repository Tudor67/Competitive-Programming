class Solution {
private:
    const int POWERS_OF_4_MASK = 0b01010101010101010101010101010101;

public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && (POWERS_OF_4_MASK & n);
    }
};