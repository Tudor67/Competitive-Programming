class Solution {
public:
    int findComplement(int num) {
        int msb = 31 - __builtin_clz((unsigned int)num);
        int fullMask = ((1U << (msb + 1)) - 1);
        int numComplement = fullMask ^ num;
        return numComplement;
    }
};