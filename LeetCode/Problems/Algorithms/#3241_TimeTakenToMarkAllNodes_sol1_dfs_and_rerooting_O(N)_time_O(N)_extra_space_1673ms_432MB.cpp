class Solution {
private:
    using Graph = vector<vector<int>>;

    int getCostTo(int to){
        return 2 - (to % 2);
    }

    void dfs(int parent, int node, const Graph& G, vector<vector<pair<int, int>>>& v){
        for(int child: G[node]){
            if(child != parent){
                dfs(node, child, G, v);
                v[node].push_back({getCostTo(child) + v[child][0].first, child});
                sort(v[node].rbegin(), v[node].rend());
                v[node].resize(min((int)v[node].size(), 2));
            }
        }

        if(v[node].empty()){
            v[node].push_back({0, node});
        }
    }

    void rerooting(int parent, int node, const Graph& G, vector<vector<pair<int, int>>>& v, vector<int>& times){
        if(parent != -1){
            if(v[parent][0].second != node){
                v[node].push_back({getCostTo(parent) + v[parent][0].first, parent});
            }else if((int)v[parent].size() >= 2){
                v[node].push_back({getCostTo(parent) + v[parent][1].first, parent});
            }else{
                v[node].push_back({getCostTo(parent), parent});
            }

            sort(v[node].rbegin(), v[node].rend());
            v[node].resize(min((int)v[node].size(), 2));
        }

        times[node] = v[node][0].first;
        
        for(int child: G[node]){
            if(child != parent){
                rerooting(node, child, G, v, times);
            }
        }
    }

public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E + 1;

        Graph G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<pair<int, int>>> v(N);
        dfs(-1, 0, G, v);

        vector<int> times(N);
        rerooting(-1, 0, G, v, times);

        return times;
    }
};