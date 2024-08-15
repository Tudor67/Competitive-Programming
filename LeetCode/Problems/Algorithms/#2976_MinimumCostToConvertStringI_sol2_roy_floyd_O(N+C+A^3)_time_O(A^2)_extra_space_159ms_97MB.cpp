class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int N = source.length();
        const int C = changed.size();
        const int A = 26;
        const int MIN_CHAR = 'a';
        const int INF = 1e9;
        
        vector<vector<int>> minCost(A, vector<int>(A, INF));
        for(int i = 0; i < C; ++i){
            int a = original[i] - MIN_CHAR;
            int b = changed[i] - MIN_CHAR;
            minCost[a][b] = min(minCost[a][b], cost[i]);
        }
        
        for(int i = 0; i < A; ++i){
            minCost[i][i] = 0;
        }
        
        for(int k = 0; k < A; ++k){
            for(int i = 0; i < A; ++i){
                for(int j = 0; j < A; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        
        long long totalCost = 0;
        for(int i = 0; i < N; ++i){
            int a = source[i] - MIN_CHAR;
            int b = target[i] - MIN_CHAR;
            if(minCost[a][b] == INF){
                return -1;
            }
            totalCost += minCost[a][b];
        }
        
        return totalCost;
    }
};