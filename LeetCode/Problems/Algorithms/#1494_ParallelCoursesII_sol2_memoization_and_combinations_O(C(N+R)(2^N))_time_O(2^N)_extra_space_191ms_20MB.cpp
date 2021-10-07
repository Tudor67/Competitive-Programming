class Solution {
private:
    void generateCombMasks(int level, int startBit, int combMask, int n, int k, vector<int>& combMasks){
        if(level == k){
            combMasks.push_back(combMask);
        }else{
            for(int bit = startBit; bit < n; ++bit){
                generateCombMasks(level + 1, bit + 1, combMask | (1 << bit), n, k, combMasks);
            }
        }
    }
    
    int solve(int mask, const int& N, const int& K, vector<vector<int>>& nextNodes, vector<int>& inDegree, vector<int>& memo){
        if(mask == 0){
            return 0;
        }
        
        if(memo[mask] != -1){
            return memo[mask];
        }
        
        int activeNodes = 0;
        for(int node = 0; node < N; ++node){
            if(((mask >> node) & 1) && inDegree[node] == 0){
                activeNodes += 1;
            }
        }
        
        vector<int> combMasks;
        generateCombMasks(0, 0, 0, activeNodes, min(K, activeNodes), combMasks);
        
        int minCost = N;
        for(int combMask: combMasks){
            int nextMask = mask;
            int activeNodeIdx = 0;
            for(int node = 0; node < N; ++node){
                if(((mask >> node) & 1) && inDegree[node] == 0){
                    if((combMask >> activeNodeIdx) & 1){
                        nextMask -= (1 << node);
                    }
                    activeNodeIdx += 1;
                }
            }
            
            for(int node = 0; node < N; ++node){
                if(((mask - nextMask) >> node) & 1){
                    for(int nextNode: nextNodes[node]){
                        inDegree[nextNode] -= 1;
                    }
                }
            }
            
            int cost = 1 + solve(nextMask, N, K, nextNodes, inDegree, memo);
            minCost = min(minCost, cost);
            
            for(int node = 0; node < N; ++node){
                if(((mask - nextMask) >> node) & 1){
                    for(int nextNode: nextNodes[node]){
                        inDegree[nextNode] += 1;
                    }
                }
            }
        }
        
        memo[mask] = minCost;
        return minCost;
    }
    
public:
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        if(relations.empty()){
            return (N + K - 1) / K;
        }
        
        const int FULL_MASK = (1 << N) - 1;
        vector<vector<int>> nextNodes(N);
        vector<int> inDegree(N);
        for(const vector<int>& R: relations){
            int x = R[0] - 1;
            int y = R[1] - 1;
            nextNodes[x].push_back(y);
            inDegree[y] += 1;
        }
        
        vector<int> memo(FULL_MASK + 1, -1);
        return solve(FULL_MASK, N, K, nextNodes, inDegree, memo);
    }
};