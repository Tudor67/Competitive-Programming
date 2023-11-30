class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1){
            return n;
        }

        int maxPow = 1;
        while(maxPow * 2 <= n){
            maxPow *= 2;
        }

        return maxPow * 2 - 1 - minimumOneBitOperations(maxPow ^ n);
    }
};