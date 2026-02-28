class Solution {
public:
    bool hasAlternatingBits(int n) {
        for(int bit = 1; (n >> bit) > 0; ++bit){
            int prevBit = (n >> (bit - 1)) & 1;
            int currBit = (n >> bit) & 1;
            if(prevBit == currBit){
                return false;
            }
        }
        return true;
    }
};