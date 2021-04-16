class Solution {
private:
    long long factorialZeros(long long n){
        long long zeros = 0;
        for(long long i = 5; i <= n; i *= 5){
            zeros += n / i;
        }
        return zeros;
    }
    
public:
    int preimageSizeFZF(int K) {
        long long l = 0;
        long long r = 1e10;
        while(l != r){
            long long mid = (l + r) / 2;
            if(factorialZeros(mid) < K){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        int answer = 0;
        if(factorialZeros(r) == K){
            answer = 5;
        }
        
        return answer;
    }
};