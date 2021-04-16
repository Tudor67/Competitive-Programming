class Solution {
private:
    long long idxFor(long long num, long long a, long long b, long long c){
        long long totalMultiples = num / a + num / b + num / c;
        long long abMultiples = num / lcm(a, b);
        long long acMultiples = num / lcm(a, c);
        long long bcMultiples = num / lcm(b, c);
        long long abcMultiples = num / lcm(a, lcm(b, c));
        long long idx = totalMultiples - abMultiples - acMultiples - bcMultiples + abcMultiples;
        return idx;
    }
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1;
        long long r = 2e9;
        while(l != r){
            long long mid = (l + r) / 2;
            if(idxFor(mid, a, b, c) < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};