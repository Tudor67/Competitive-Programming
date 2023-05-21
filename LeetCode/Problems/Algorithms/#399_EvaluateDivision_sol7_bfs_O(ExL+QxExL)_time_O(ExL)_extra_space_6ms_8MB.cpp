class Solution {
private:
    using Graph = unordered_map<string, vector<pair<string, double>>>;

    double computeDist(string src, string dest, Graph& G){
        if(!G.count(src) || !G.count(dest)){
            return -1;
        }
        
        unordered_map<string, double> dist;
        queue<string> q;
        q.push(src);
        dist[src] = 1;

        while(!q.empty() && !dist.count(dest)){
            string a = q.front();
            q.pop();

            for(const pair<string, double>& P: G[a]){
                string b = P.first;
                double w = P.second;
                if(!dist.count(b)){
                    dist[b] = dist[a] * w;
                    q.push(b);
                }
            }
        }

        if(dist.count(dest)){
            return dist[dest];
        }

        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E = equations.size();
        const int Q = queries.size();

        Graph G;
        for(int i = 0; i < E; ++i){
            string a = equations[i][0];
            string b = equations[i][1];
            double w = values[i];
            G[a].push_back({b, w});
            G[b].push_back({a, 1.0 / w});
        }

        vector<double> res(Q);
        for(int i = 0; i < Q; ++i){
            string c = queries[i][0];
            string d = queries[i][1];
            res[i] = computeDist(c, d, G);
        }

        return res;
    }
};