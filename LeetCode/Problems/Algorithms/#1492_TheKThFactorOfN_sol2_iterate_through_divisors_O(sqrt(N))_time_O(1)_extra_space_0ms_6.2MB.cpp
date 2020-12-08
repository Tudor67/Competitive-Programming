class Solution {
public:
    int kthFactor(int n, int k) {
        int factorsCount = 0;
        for(int i = 1; i * i <= n; ++i){
            if(n % i == 0){
                factorsCount += 2;
            }
        }
        
        if((int)sqrt(n) * (int)sqrt(n) == n){
            factorsCount -= 1;
        }
        
        int answer = -1;
        if(k <= factorsCount){
            int factorIdx = 0;
            for(int i = 1; answer == -1 && i * i <= n; ++i){
                if(n % i == 0){
                    factorIdx += 1;
                    if(factorIdx == k){
                        answer = i;
                    }else if(factorIdx + k - 1 == factorsCount){
                        answer = n / i;
                    }
                }
            }
        }
        
        return answer;
    }
};