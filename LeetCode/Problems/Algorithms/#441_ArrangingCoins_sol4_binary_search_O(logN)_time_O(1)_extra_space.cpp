class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1;
        long long r = n + 1LL;
        while(l != r){
            long long mid = (l + r) / 2;
            if(mid * (mid + 1) / 2 <= n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r - 1;
    }
};