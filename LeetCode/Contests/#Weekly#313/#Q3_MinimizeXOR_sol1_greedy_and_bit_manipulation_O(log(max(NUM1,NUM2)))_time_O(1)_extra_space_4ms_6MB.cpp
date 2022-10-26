class Solution {
public:
    int minimizeXor(int num1, int num2) {
        const int MAX_BIT = floor(log2(max(num1, num2)));
        
        int x = 0;
        int remBits = __builtin_popcount((unsigned int)num2);
        
        for(int bit = MAX_BIT; bit >= 0; --bit){
            if((num1 >> bit) & 1){
                if(remBits >= 1){
                    x |= (1 << bit);
                    remBits -= 1;
                }
            }
        }
        
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(((x >> bit) & 1) == 0){
                if(remBits >= 1){
                    x |= (1 << bit);
                    remBits -= 1;
                }
            }
        }
        
        return x;
    }
};