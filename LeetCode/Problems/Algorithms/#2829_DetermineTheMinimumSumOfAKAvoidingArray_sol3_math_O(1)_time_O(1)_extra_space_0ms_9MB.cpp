class Solution {
private:
    int getRangeSum(int l, int r){
        return r * (r + 1) / 2 - (l - 1) * l / 2;
    }

public:
    int minimumSum(int n, int k) {
        if(n <= k / 2){
            return getRangeSum(1, n);
        }
        return getRangeSum(1, k / 2) +
               getRangeSum(k, k + n - k / 2 - 1);
    }
};