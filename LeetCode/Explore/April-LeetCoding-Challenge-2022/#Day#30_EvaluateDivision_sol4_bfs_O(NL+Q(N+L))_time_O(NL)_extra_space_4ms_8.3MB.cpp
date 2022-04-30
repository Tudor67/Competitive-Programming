class Solution {
private:
    double bfs(const int& SRC_NODE, const int& DEST_NODE, vector<vector<pair<int, double>>>& g){
        if(SRC_NODE == DEST_NODE){
            return 1;
        }
        
        queue<pair<int, double>> q;
        unordered_set<int> vis;
        q.emplace(SRC_NODE, 1);
        vis.insert(SRC_NODE);
        
        while(!q.empty()){
            int node = q.front().first;
            double nodeCost = q.front().second;
            q.pop();
            
            for(const pair<int, double>& P: g[node]){
                int nextNode = P.first;
                double transitionCost = P.second;
                if(!vis.count(nextNode)){
                    double nextNodeCost = nodeCost * transitionCost;
                    q.emplace(nextNode, nextNodeCost);
                    vis.insert(nextNode);
                    
                    if(nextNode == DEST_NODE){
                        return nextNodeCost;
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E = equations.size();
        const int Q = queries.size();
        
        unordered_map<string, int> idxOf;
        int maxIdx = -1;
        for(int i = 0; i < E; ++i){
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            if(!idxOf.count(A)){
                idxOf[A] = ++maxIdx;
            }
            if(!idxOf.count(B)){
                idxOf[B] = ++maxIdx;
            }
        }
        
        const int N = maxIdx + 1;
        vector<vector<pair<int, double>>> g(N);
        for(int i = 0; i < E; ++i){
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            g[idxOf[A]].emplace_back(idxOf[B], values[i]);
            g[idxOf[B]].emplace_back(idxOf[A], 1.0 / values[i]);
        }
        
        vector<double> res(Q);
        for(int j = 0; j < Q; ++j){
            const string& A = queries[j][0];
            const string& B = queries[j][1];
            if(idxOf.count(A) && idxOf.count(B)){
                res[j] = bfs(idxOf[A], idxOf[B], g);
            }else{
                res[j] = -1;
            }
        }
        
        return res;
    }
};