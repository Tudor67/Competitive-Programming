class Solution {
public:
    int findNthDigit(int n) {
        long long count = 0;
        long long d = 1;
        long long p = 1;
        while(count + d * 9 * p < n){
            count += d * 9 * p;
            d += 1;
            p *= 10;
        }
        
        long long x = p + (n - count - 1) / d;
        long long digits = count + ((n - count - 1) / d + 1) * d;
        string xStr = to_string(x);
        int idx = (int)xStr.length() - 1 - (digits - n);
        int nThDigit = xStr[idx] - '0';
        
        return nThDigit;
    }
};