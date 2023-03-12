class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while(n > 0){
            if(n & 1){
                if((n & 3) == 3){
                    // consecutive ones => add 2^k
                    n += 1;
                    res += 1;
                }else{
                    // single one => subtract 2^k
                    res += 1;
                }
            }
            n >>= 1;
        }
        return res;
    }
};