class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, int ccId, vector<int>& ccIdOf, const Graph& G){
        if(ccIdOf[node] >= 0){
            return;
        }
        ccIdOf[node] = ccId;
        for(int nextNode: G[node]){
            dfs(nextNode, ccId, ccIdOf, G);
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        const int E = connections.size();
        const int Q = queries.size();

        Graph G(c + 1);
        for(vector<int>& edge: connections){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int ccId = -1;
        vector<int> ccIdOf(c + 1, -1);
        for(int node = 1; node <= c; ++node){
            if(ccIdOf[node] < 0){
                ccId += 1;
                dfs(node, ccId, ccIdOf, G);
            }
        }

        vector<vector<int>> cc(ccId + 1);
        for(int node = c; node >= 1; --node){
            cc[ccIdOf[node]].push_back(node);
        }

        vector<int> res;
        vector<bool> isOnline(c + 1, true);
        
        for(vector<int>& query: queries){
            int queryType = query[0];
            int x = query[1];
            vector<int>& ccNodes = cc[ccIdOf[x]];

            if(queryType == 1){
                if(isOnline[x]){
                    res.push_back(x);
                }else{
                    while(!ccNodes.empty() && !isOnline[ccNodes.back()]){
                        ccNodes.pop_back();
                    }
                    if(!ccNodes.empty()){
                        res.push_back(ccNodes.back());
                    }else{
                        res.push_back(-1);
                    }
                }
            }else{
                isOnline[x] = false;
            }
        }

        return res;
    }
};