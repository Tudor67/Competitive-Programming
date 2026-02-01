class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int N = source.length();
        const int C = cost.size();
        const int A = 26;
        const int INF = 1e9;

        vector<vector<int>> minCost(A, vector<int>(A, INF));
        for(int i = 0; i < A; ++i){
            minCost[i][i] = 0;
        }

        for(int i = 0; i < C; ++i){
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            int abCost = cost[i];
            minCost[a][b] = min(minCost[a][b], abCost);
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
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(minCost[a][b] == INF){
                return -1;
            }
            totalCost += minCost[a][b];
        }

        return totalCost;
    }
};