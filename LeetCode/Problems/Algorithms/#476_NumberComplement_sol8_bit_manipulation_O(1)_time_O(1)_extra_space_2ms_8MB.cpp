class Solution {
public:
    int findComplement(int num) {
        int fullMask = num;
        for(int shift = 1; shift <= 16; shift *= 2){
            fullMask |= (fullMask >> shift);
        }
        return (fullMask ^ num);
    }
};