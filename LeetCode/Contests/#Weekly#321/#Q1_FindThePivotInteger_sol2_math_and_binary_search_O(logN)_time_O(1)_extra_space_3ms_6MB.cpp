class Solution {
private:
    int computeLeftSum(int x){
        return x * (x + 1) / 2;
    }

    int computeRightSum(int x, int n){
        return n * (n + 1) / 2 - x * (x + 1) / 2 + x;
    }

public:
    int pivotInteger(int n) {
        int l = 0;
        int r = n;
        while(l != r){
            int mid = (l + r) / 2;
            int leftSum = computeLeftSum(mid);
            int rightSum = computeRightSum(mid, n);
            if(leftSum == rightSum){
                l = mid;
                r = mid;
            }else if(leftSum < rightSum){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(computeLeftSum(r) == computeRightSum(r, n)){
            return r;
        }
        
        return -1;
    }
};