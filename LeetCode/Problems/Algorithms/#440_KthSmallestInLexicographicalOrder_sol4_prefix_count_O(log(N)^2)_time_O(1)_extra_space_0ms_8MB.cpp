class Solution {
private:
    long long prefixCount(long long x, long long n){
        long long count = 0;
        long long p = 1;
        while(x * p <= n){
            count += min(n + 1, (x + 1) * p) - x * p;
            p *= 10;
        }
        return count;
    }

public:
    int findKthNumber(int n, int k) {
        long long x = 1;
        while(k > 1){
            long long count = prefixCount(x, n);
            if(count < k){
                x += 1;
                k -= count;
            }else{
                x *= 10;
                k -= 1;
            }
        }
        return x;
    }
};