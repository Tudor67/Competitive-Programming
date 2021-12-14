class Solution {
private:
    long long countMultiples(const long long& A, const long long& B, const long long& AB_LCM, const long long& LIM){
        long long aMultiples = LIM / A;
        long long bMultiples = LIM / B;
        long long abMultiples = LIM / AB_LCM;
        return aMultiples + bMultiples - abMultiples;
    }
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MODULO = 1e9 + 7;
        long long abLCM = lcm(a, b);
        long long l = min(a, b);
        long long r = min(a, b) * 1LL * n;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countMultiples(a, b, abLCM, mid) < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r % MODULO;
    }
};