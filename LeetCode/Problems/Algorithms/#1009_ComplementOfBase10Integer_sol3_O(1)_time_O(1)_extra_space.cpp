class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int fullMask = n;
        fullMask |= fullMask >> 1;
        fullMask |= fullMask >> 2;
        fullMask |= fullMask >> 4;
        fullMask |= fullMask >> 8;
        fullMask |= fullMask >> 16;
        return fullMask ^ n;
    }
};