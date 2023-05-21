class Solution {
private:
    using Graph = vector<vector<pair<int, double>>>;

    double computeDist(int src, int dest, Graph& G){
        if(src == 0 || dest == 0){
            return -1;
        }
        
        const int N = G.size();
        vector<double> dist(N);
        queue<int> q;
        q.push(src);
        dist[src] = 1;

        while(!q.empty() && dist[dest] == 0){
            int a = q.front();
            q.pop();

            for(const pair<int, double>& P: G[a]){
                int b = P.first;
                double w = P.second;
                if(dist[b] == 0){
                    dist[b] = dist[a] * w;
                    q.push(b);
                }
            }
        }

        if(dist[dest] != 0){
            return dist[dest];
        }

        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E = equations.size();
        const int Q = queries.size();

        unordered_map<string, int> strToNode;
        for(int i = 0; i < E; ++i){
            for(string s: {equations[i][0], equations[i][1]}){
                if(!strToNode.count(s)){
                    int node = 1 + strToNode.size();
                    strToNode[s] = node;
                }
            }
        }

        const int N = strToNode.size();
        Graph G(N + 1);
        for(int i = 0; i < E; ++i){
            int a = strToNode[equations[i][0]];
            int b = strToNode[equations[i][1]];
            double w = values[i];
            G[a].push_back({b, w});
            G[b].push_back({a, 1.0 / w});
        }

        vector<double> res(Q);
        for(int i = 0; i < Q; ++i){
            int c = strToNode[queries[i][0]];
            int d = strToNode[queries[i][1]];
            res[i] = computeDist(c, d, G);
        }

        return res;
    }
};