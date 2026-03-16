class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        return (1 << bit_width((unsigned int)n)) - 1 - n;
    }
};