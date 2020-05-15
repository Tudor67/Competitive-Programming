class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1;
        long long r = num;
        
        while(l != r){
            long long mid = l + (r - l) / 2;
            if(mid * mid < num)
                l = mid + 1;
            else
                r = mid;
        }
        
        return (r * r == num);
    }
};