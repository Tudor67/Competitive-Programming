class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MODULO = 1e9 + 7;
        vector<int> count(k + 1, 0);
        count[0] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = k; j >= 1; --j){
                for(int p = j - 1; p >= max(0, j - i + 1); --p){
                    count[j] += count[p];
                    count[j] %= MODULO;
                }
            }
        }
        return count[k];
    }
};