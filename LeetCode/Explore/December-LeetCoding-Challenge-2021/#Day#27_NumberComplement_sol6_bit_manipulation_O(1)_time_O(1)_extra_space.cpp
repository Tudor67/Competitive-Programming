class Solution {
public:
    int findComplement(int num) {
        int fullMask = num;
        fullMask |= fullMask >> 1;
        fullMask |= fullMask >> 2;
        fullMask |= fullMask >> 4;
        fullMask |= fullMask >> 8;
        fullMask |= fullMask >> 16;
        int numComplement = fullMask ^ num;
        return numComplement;
    }
};