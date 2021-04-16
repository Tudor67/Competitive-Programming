class Solution {
private:
    long long getSum(long long n){
        if(n <= 0){
            return 0;
        }
        return n * (n + 1) / 2;
    }
    
    long long getMinSum(int n, int index, int val){
        long long minSum = 0;
        minSum += getSum(val) - getSum(val - (index + 1));
        minSum += getSum(val) - getSum(val - (n - index));
        minSum -= val;
        return minSum;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0;
        int r = maxSum;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(getMinSum(n, index, mid) <= maxSum){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r + 1;
    }
};