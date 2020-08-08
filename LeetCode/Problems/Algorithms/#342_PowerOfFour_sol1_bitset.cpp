class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num >= 1 && 
                bitset<32>(num).count() == 1 &&
                bitset<32>(num - 1).count() % 2 == 0);
    }
};