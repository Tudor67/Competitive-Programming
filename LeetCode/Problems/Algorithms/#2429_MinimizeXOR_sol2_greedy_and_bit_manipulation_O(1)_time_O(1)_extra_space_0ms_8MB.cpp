class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int remBits = __builtin_popcount(num2);

        int x = 0;
        for(int bit = 30; bit >= 0 && remBits >= 1; --bit){
            if((num1 >> bit) & 1){
                x |= (1 << bit);
                remBits -= 1;
            }
        }

        for(int bit = 0; bit <= 30 && remBits >= 1; ++bit){
            if(!((x >> bit) & 1)){
                x |= (1 << bit);
                remBits -= 1;
            }
        }
        
        return x;
    }
};