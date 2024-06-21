class Solution {
private:
    bool isSquare(unsigned int target){
        if(target == 0){
            return true;
        }
        unsigned int l = 1;
        unsigned int r = target;
        while(l != r){
            unsigned int mid = (l + r) / 2;
            if(mid < target / mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return (r * r == target);
    }

public:
    bool judgeSquareSum(int c) {
        for(unsigned int a = 0; a * a <= c; ++a){
            if(isSquare(c - a * a)){
                return true;
            }
        }
        return false;
    }
};