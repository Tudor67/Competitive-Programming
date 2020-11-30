class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int rem = 0;
        for(int i = 1; i <= K + 1; ++i){
            rem = 10 * rem + 1;
            if(rem >= K){
                rem %= K;
            }
            if(rem == 0){
                return i;
            }
        }
        return -1;
    }
};