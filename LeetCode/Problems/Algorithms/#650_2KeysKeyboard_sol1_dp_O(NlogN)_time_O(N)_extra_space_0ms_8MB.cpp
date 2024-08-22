class Solution {
public:
    int minSteps(int n) {
        vector<int> minOps(n + 2);

        for(int i = 2; i <= n; ++i){
            minOps[i] = i;
        }

        for(int i = 2; i <= n; ++i){
            for(int j = i + i; j <= n; j += i){
                minOps[j] = min(minOps[j], minOps[i] + 1 + (j - i) / i);
            }
        }

        return minOps[n];
    }
};