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
    
public:
    int numTrees(int n) {
        return comb(2 * n, n) / (n + 1);
    }
};