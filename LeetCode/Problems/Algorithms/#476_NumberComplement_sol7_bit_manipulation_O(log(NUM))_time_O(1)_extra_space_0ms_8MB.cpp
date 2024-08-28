class Solution {
public:
    int findComplement(int num) {
        int complement = 0;
        for(int bit = 0; (num >> bit) > 0; ++bit){
            if(((num >> bit) & 1) == 0){
                complement |= (1 << bit);
            }
        }
        return complement;
    }
};