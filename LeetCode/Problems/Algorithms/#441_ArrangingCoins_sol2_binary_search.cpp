class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        while(l != r){
            int mid = l + (r - l + 1LL) / 2;
            if(mid * (mid + 1LL) / 2 > n){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return r;
    }
};