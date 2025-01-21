class Solution {
private:
    bool isSetBit(int num, int bit){
        return (num >> bit) & 1;
    }

    void setBit(int& num, int bit){
        num |= (1 << bit);
    }

public:
    int minimizeXor(int num1, int num2) {
        int remBits = __builtin_popcount(num2);

        int x = 0;
        for(int bit = 30; bit >= 0 && remBits >= 1; --bit){
            if(isSetBit(num1, bit)){
                setBit(x, bit);
                remBits -= 1;
            }
        }

        for(int bit = 0; bit <= 30 && remBits >= 1; ++bit){
            if(!isSetBit(x, bit)){
                setBit(x, bit);
                remBits -= 1;
            }
        }
        
        return x;
    }
};