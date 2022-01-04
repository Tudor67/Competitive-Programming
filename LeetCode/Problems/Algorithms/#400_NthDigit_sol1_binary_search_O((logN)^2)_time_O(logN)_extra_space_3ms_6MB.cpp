class Solution {
private:
    long long countDigits(long long x){
        long long count = 0;
        long long d = 1;
        long long p = 1;
        while(p <= x / 10){
            count += d * 9 * p;
            d += 1;
            p *= 10;
        }
        count += (x - p + 1) * d;
        return count;
    }
    
public:
    int findNthDigit(int n) {
        long long l = 1;
        long long r = n;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countDigits(mid) < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        long long x = r;
        long long digits = countDigits(x);
        string xStr = to_string(x);
        int idx = (int)xStr.length() - 1 - (digits - n);
        int nThDigit = xStr[idx] - '0';
        
        return nThDigit;
    }
};