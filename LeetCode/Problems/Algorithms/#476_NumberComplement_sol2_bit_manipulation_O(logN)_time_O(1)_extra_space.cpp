class Solution {
public:
    int findComplement(int num) {
        int numComplement = 0;
        for(int bit = 0; bit <= 30 && (1 << bit) <= num; ++bit){
            if(((num >> bit) & 1) == 0){
                numComplement |= (1 << bit);
            }
        }
        return numComplement;
    }
};