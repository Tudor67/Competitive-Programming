class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int N = source.length();
        const int C = changed.size();
        const long long INF = 1e16;

        unordered_map<string, int> strToNode;
        for(int i = 0; i < C; ++i){
            if(!strToNode.count(original[i])){
                int id = strToNode.size();
                strToNode[original[i]] = id;
            }
            if(!strToNode.count(changed[i])){
                int id = strToNode.size();
                strToNode[changed[i]] = id;
            }
        }

        // Roy-Floyd Algorithm
        // minCost[strToNode[originalStr]][strToNode[changedStr]]: min cost to convert
        //                                                         originalStr to changedStr
        const int TOTAL_NODES = strToNode.size();
        vector<vector<long long>> minCost(TOTAL_NODES, vector<long long>(TOTAL_NODES, INF));
        for(int i = 0; i < C; ++i){
            int a = strToNode[original[i]];
            int b = strToNode[changed[i]];
            minCost[a][b] = min(minCost[a][b], (long long)cost[i]);
        }

        for(int i = 0; i < TOTAL_NODES; ++i){
            minCost[i][i] = 0;
        }

        for(int k = 0; k < TOTAL_NODES; ++k){
            for(int i = 0; i < TOTAL_NODES; ++i){
                for(int j = 0; j < TOTAL_NODES; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        
        // dp[i]: min cost to convert source[i .. N - 1] to target[i .. N - 1]
        vector<long long> dp(N + 1, INF);
        dp[N] = 0;

        for(int i = N - 1; i >= 0; --i){
            string aStr;
            string bStr;
            for(int j = i; j < N; ++j){
                aStr += source[j];
                bStr += target[j];
                if(dp[j + 1] != INF && strToNode.count(aStr) && strToNode.count(bStr)){
                    dp[i] = min(dp[i], minCost[strToNode[aStr]][strToNode[bStr]] + dp[j + 1]);
                }
                if(dp[j + 1] != INF && aStr == bStr){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        if(dp[0] == INF){
            dp[0] = -1;
        }

        return dp[0];
    }
};