class Solution {
private:
    int binarySearchSQRT(const int& X){
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
        return r;
    }
    
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = binarySearchSQRT(c);
        while(a <= b){
            if(a * a < c - b * b){
                a += 1;
            }else if(a * a > c - b * b){
                b -= 1;
            }else{
                return true;
            }
        }
        return false;
    }
};