class Solution {
public:
    int findComplement(int num) {
        int maxPow = 1;
        for(int x = num; x > 0; x &= (x - 1)){
            maxPow = x;
        }
        
        int fullMask = 2U * maxPow - 1;
        int numComplement = fullMask ^ num;
        
        return numComplement;
    }
};