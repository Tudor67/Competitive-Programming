class Solution {
private:
    long long prefixCount(long long x, long long n){
        long long count = 0;
        long long p10 = 1;
        while(p10 * x <= n){
            count += min(n + 1, p10 * (x + 1)) - p10 * x;
            p10 *= 10;
        }
        return count;
    }

public:
    int findKthNumber(int n, int k) {
        long long x = 1;
        while(k > 1){
            int count = prefixCount(x, n);
            if(count < k){
                k -= count;
                x += 1;
            }else{
                k -= 1;
                x *= 10;
            }
        }
        return x;
    }
};