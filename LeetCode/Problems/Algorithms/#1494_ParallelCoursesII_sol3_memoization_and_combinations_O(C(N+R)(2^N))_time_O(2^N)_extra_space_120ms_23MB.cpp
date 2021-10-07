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
    
    int solve(int& mask, const int& N, const int& K, vector<vector<int>>& nextNodes, vector<int>& inDegree, vector<int>& memo){
        if(mask == 0){
            return 0;
        }
        
        if(memo[mask] != -1){
            return memo[mask];
        }
        
        vector<int> activeNodes;
        for(int node = 0; node < N; ++node){
            if(((mask >> node) & 1) && inDegree[node] == 0){
                activeNodes.push_back(node);
            }
        }
        
        const int ACTIVE_SIZE = activeNodes.size();
        vector<int> combMasks;
        generateCombMasks(0, 0, 0, ACTIVE_SIZE, min(K, ACTIVE_SIZE), combMasks);
        
        int minCost = N;
        for(int combMask: combMasks){
            for(int bit = 0; bit < ACTIVE_SIZE; ++bit){
                if((combMask >> bit) & 1){
                    mask -= (1 << activeNodes[bit]);
                    for(int nextNode: nextNodes[activeNodes[bit]]){
                        inDegree[nextNode] -= 1;
                    }
                }
            }
            
            int cost = 1 + solve(mask, N, K, nextNodes, inDegree, memo);
            minCost = min(minCost, cost);
            
            for(int bit = 0; bit < ACTIVE_SIZE; ++bit){
                if((combMask >> bit) & 1){
                    mask += (1 << activeNodes[bit]);
                    for(int nextNode: nextNodes[activeNodes[bit]]){
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
        
        int mask = FULL_MASK;
        vector<int> memo(FULL_MASK + 1, -1);
        int minCost = solve(mask, N, K, nextNodes, inDegree, memo);
        
        return minCost;
    }
};