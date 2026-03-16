class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }

        int complement = 0;
        for(int bit = 0; (1 << bit) <= n; ++bit){
            if(((n >> bit) & 1) == 0){
                complement |= (1 << bit);
            }
        }
        
        return complement;
    }
};