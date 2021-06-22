class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MODULO = 1e9 + 7;
        vector<int> count(k + 1, 0);
        count[0] = 1;
        for(int i = 2; i <= n; ++i){
            int sum = 0;
            for(int p = k - 1; p >= max(0, k - i + 1); --p){
                sum += count[p];
                sum %= MODULO;
            }
            for(int j = k; j >= 1; --j){
                count[j] += sum;
                count[j] %= MODULO;
                sum -= count[j - 1];
                sum += MODULO;
                sum %= MODULO;
                if(j - i >= 0){
                    sum += count[j - i];
                    sum %= MODULO;
                }
            }
        }
        return count[k];
    }
};