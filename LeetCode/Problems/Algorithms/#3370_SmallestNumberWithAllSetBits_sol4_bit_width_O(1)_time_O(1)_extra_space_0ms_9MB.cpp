class Solution {
public:
    int smallestNumber(int n) {
        return (1 << bit_width((unsigned int)n)) - 1;
    }
};