class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int n1, int n2) {
        long long lcmVal = lcm((long long)divisor1, (long long)divisor2);
        long long l = n1 + n2;
        long long r = INT_MAX;
        while(l != r){
            long long mid = (l + r) / 2;
            if(mid - mid / divisor1 >= n1 &&
               mid - mid / divisor2 >= n2 &&
               mid - mid / lcmVal >= n1 + n2){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};