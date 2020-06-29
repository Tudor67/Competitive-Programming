class Solution {
private:
    long long comb(int n, int k){
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }
    
    int catalan_number(int n){
        return int(comb(2 * n, n) / (n + 1));
    }
    
public:
    int numTrees(int n) {
        return catalan_number(n);
    }
};