class Solution {
public:
    bool hasAlternatingBits(int n) {
        const int MAX_BIT = 30;
        
        int msb = MAX_BIT;
        while(msb >= 0 && ((n >> msb) & 1) == 0){
            msb -= 1;
        }
        
        for(int bit = msb; bit >= 0; --bit){
            int prevBitVal = (n >> (bit + 1)) & 1;
            int curBitVal = (n >> bit) & 1;
            if(prevBitVal == curBitVal){
                return false;
            }
        }
        
        return true;
    }
};