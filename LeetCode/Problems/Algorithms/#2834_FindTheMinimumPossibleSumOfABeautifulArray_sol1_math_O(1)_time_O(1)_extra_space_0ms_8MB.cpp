class Solution {
private:
    long long getRangeSum(long long l, long long r){
        return r * (r + 1) / 2 - (l - 1) * l / 2;
    }
    
public:
    int minimumPossibleSum(int n, int target) {
        const long long MODULO = 1e9 + 7;
        
        if(n == 1){
            return 1;
        }
        
        if(n <= target / 2){
            return getRangeSum(1, n) % MODULO;
        }
        
        return (getRangeSum(1, target / 2) +
                getRangeSum(target, target + n - target / 2 - 1)) % MODULO;
    }
};