class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        while(n - k >= 0){
            n -= k;
            k += 1;
        }
        return k - 1;
    }
};