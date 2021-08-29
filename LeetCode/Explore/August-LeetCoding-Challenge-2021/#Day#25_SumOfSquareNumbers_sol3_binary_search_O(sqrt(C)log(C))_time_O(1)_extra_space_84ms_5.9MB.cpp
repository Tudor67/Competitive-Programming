class Solution {
private:
    bool isPerfectSquare(const int& X){
        int l = 0;
        int r = X;
        while(l != r){
            int mid = l + (r - l) / 2 + 1;
            if(mid <= X / mid){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return (r * r == X);
    }
    
public:
    bool judgeSquareSum(int c) {
        for(int b = 0; b == 0 || b <= c / b; ++b){
            int bSquared = b * b;
            int complement = c - b * b;
            if(isPerfectSquare(complement)){
                return true;
            }
        }
        return false;
    }
};