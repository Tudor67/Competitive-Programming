class Solution {
private:
    using Arc = pair<string, double>;
    
    double bfs(const string& SRC_NODE, const string& DEST_NODE, unordered_map<string, vector<Arc>>& arcsFrom){
        if(!arcsFrom.count(SRC_NODE) || !arcsFrom.count(DEST_NODE)){
            return -1;
        }
        
        if(SRC_NODE == DEST_NODE){
            return 1;
        }
        
        queue<pair<string, double>> q;
        unordered_set<string> vis;
        q.emplace(SRC_NODE, 1);
        vis.insert(SRC_NODE);
        while(!q.empty()){
            string node = q.front().first;
            double nodeCost = q.front().second;
            q.pop();
            
            for(const Arc& ARC: arcsFrom[node]){
                string nextNode = ARC.first;
                double transitionCost = ARC.second;
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
        
        unordered_map<string, vector<Arc>> arcsFrom;
        for(int i = 0; i < E; ++i){
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            arcsFrom[A].emplace_back(B, values[i]);
            arcsFrom[B].emplace_back(A, 1.0 / values[i]);
        }
        
        vector<double> res(Q);
        for(int j = 0; j < Q; ++j){
            const string& A = queries[j][0];
            const string& B = queries[j][1];
            res[j] = bfs(A, B, arcsFrom);
        }
        
        return res;
    }
};