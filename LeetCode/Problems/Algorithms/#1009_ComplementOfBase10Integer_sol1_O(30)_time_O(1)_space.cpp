class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0){
            return 1;
        }
        
        int complement = 0;
        int msbFound = false;
        for(int bit = 30; bit >= 0; --bit){
            if((N >> bit) & 1){
                msbFound = true;
            }
            if(msbFound && (((N >> bit) & 1) == 0)){
                complement |= (1 << bit);
            }
        }
        
        return complement;
    }
};