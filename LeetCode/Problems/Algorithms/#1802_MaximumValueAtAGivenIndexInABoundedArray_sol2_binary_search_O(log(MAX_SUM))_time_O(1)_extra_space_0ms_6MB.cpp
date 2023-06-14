class Solution {
private:
    long long prefSum(long long n){
        n = max(0LL, n);
        return n * (n + 1) / 2;
    }

    bool isPossible(long long n, long long index, long long maxSum, long long maxNum){
        maxSum -= n;
        maxNum -= 1;
        long long leftSum = prefSum(maxNum) - prefSum(maxNum - (index + 1)) - maxNum;
        long long rightSum = prefSum(maxNum) - prefSum(maxNum - (n - index)) - maxNum;
        return (leftSum + maxNum + rightSum <= maxSum);
    }

public:
    int maxValue(int n, int index, int maxSum) {
        long long l = 0;
        long long r = maxSum;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(isPossible(n, index, maxSum, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};