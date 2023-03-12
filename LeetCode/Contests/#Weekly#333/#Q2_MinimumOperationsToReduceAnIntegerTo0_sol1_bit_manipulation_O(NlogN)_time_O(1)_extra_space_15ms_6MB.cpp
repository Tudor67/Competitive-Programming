class Solution {
private:
    int countOneBits(int n){
        int oneBits = 0;
        while(n > 0){
            n = (n & (n - 1));
            oneBits += 1;
        }
        return oneBits;
    }
    
public:
    int minOperations(int n) {
        int res = countOneBits(n);
        for(int i = 1; i <= n; ++i){
            int newN = i + n;
            int cost = countOneBits(i) + countOneBits(newN);
            res = min(res, cost);
        }
        return res;
    }
};