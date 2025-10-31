class Solution {
public:
    int smallestNumber(int n) {
        int res = n;
        res |= res >> 1;
        res |= res >> 2;
        res |= res >> 4;
        res |= res >> 8;
        return res;
    }
};