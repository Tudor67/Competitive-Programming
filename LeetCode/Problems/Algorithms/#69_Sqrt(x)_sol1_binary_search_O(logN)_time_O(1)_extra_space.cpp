class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l != r){
            int mid = l + (r - l) / 2 + (r - l) % 2;
            if(mid <= x / mid){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};