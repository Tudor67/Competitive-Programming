class Solution {
private:
    int rangeSum(int l, int r){
        if(l > r){
            return 0;
        }
        return r * (r + 1) / 2 - (l - 1) * l / 2;
    }
    
public:
    int pivotInteger(int n) {
        int l = 1;
        int r = n;
        while(l != r){
            int mid = (l + r) / 2;
            int leftSum = rangeSum(1, mid);
            int rightSum = rangeSum(mid + 1, n);
            if(leftSum < rightSum){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(rangeSum(1, r) == rangeSum(r, n)){
            return r;
        }

        return -1;
    }
};