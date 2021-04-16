class Solution {
private:
    long long countMagicalNumbers(int a, int b, const long long& NUM){
        long long aDivisors = NUM / a;
        long long bDivisors = NUM / b;
        long long abDivisors = NUM / (lcm(a, b));
        return (aDivisors + bDivisors - abDivisors);
    }
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 2;
        long long r = 1LL * n * min(a, b);
        while(l != r){
            long long mid = (l + r) / 2;
            if(countMagicalNumbers(a, b, mid) < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        const int MODULO = 1e9 + 7;
        int answer = r % MODULO;
        
        return answer;
    }
};