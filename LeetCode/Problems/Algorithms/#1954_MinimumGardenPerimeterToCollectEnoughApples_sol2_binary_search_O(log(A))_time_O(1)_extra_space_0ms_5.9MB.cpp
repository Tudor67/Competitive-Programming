class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1;
        long long r = min(100005LL, neededApples);
        while(l != r){
            long long mid = (l + r) / 2;
            if(2 * mid * (mid + 1) * (2 * mid + 1) < neededApples){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return 8 * r;
    }
};