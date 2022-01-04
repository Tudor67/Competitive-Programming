class Solution {
private:
    long long prefixCount(long long x, long long n){
        // compute how many numbers in range [1 .. n] have the prefix to_string(x)
        // we should count numbers from the following ranges:
        // [x, x + 1)
        // [x * 10, (x + 1) * 10)
        // [x * 100, (x + 1) * 100)
        // ...
        // [x * 10 ^ k, min((x + 1) * 10^k, n + 1))
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