class Solution {
private:
    void bfs(int srcNode, const int& CC_IDX, vector<int>& ccIdxOf, const vector<vector<int>>& G){
        queue<int> q;
        q.push(srcNode);
        ccIdxOf[srcNode] = CC_IDX;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(ccIdxOf[nextNode] == 0){
                    q.push(nextNode);
                    ccIdxOf[nextNode] = CC_IDX;
                }
            }
        }
    }
    
public:
    long long countPairs(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        int ccIdx = 0;
        vector<int> ccIdxOf(N);
        for(int node = 0; node < N; ++node){
            if(ccIdxOf[node] == 0){
                ccIdx += 1;
                bfs(node, ccIdx, ccIdxOf, G);
            }
        }
        
        const int MAX_CC_IDX = ccIdx;
        vector<int> sizeOf(MAX_CC_IDX + 1);
        for(int node = 0; node < N; ++node){
            sizeOf[ccIdxOf[node]] += 1;
        }
        
        long long pairs = 0;
        for(int node = 0; node < N; ++node){
            pairs += (N - sizeOf[ccIdxOf[node]]);
        }
        
        return pairs / 2;
    }
};