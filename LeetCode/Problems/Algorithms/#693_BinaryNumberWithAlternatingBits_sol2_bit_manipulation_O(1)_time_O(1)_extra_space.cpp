class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = !(n % 2);
        while(n != 0){
            int curBit = n % 2;
            if(prevBit == curBit){
                return false;
            }
            prevBit = curBit;
            n /= 2;
        }
        return true;
    }
};