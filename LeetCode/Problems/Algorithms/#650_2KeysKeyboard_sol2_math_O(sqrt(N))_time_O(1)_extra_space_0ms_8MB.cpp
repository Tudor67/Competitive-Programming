class Solution {
public:
    int minSteps(int n) {
        int totalOps = 0;
        for(int i = 2; i * i <= n; ++i){
            while(n % i == 0){
                totalOps += i;
                n /= i;
            }
        }

        if(n > 1){
            totalOps += n;
        }

        return totalOps;
    }
};