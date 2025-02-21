class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, const Graph& G, vector<int>& order){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G, order);
        }
        order.push_back(node);
    }

public:
    string smallestNumber(string pattern) {
        const int N = pattern.length();

        vector<vector<int>> G(N + 1);
        for(int i = 0; i < N; ++i){
            if(pattern[i] == 'I'){
                G[i + 1].push_back(i);
            }else{
                G[i].push_back(i + 1);
            }
        }

        vector<int> order;
        order.reserve(N + 1);
        vector<bool> vis(N + 1, false);
        for(int node = 0; node <= N; ++node){
            dfs(node, vis, G, order);
        }

        string res(N + 1, '0');
        for(int i = 0; i <= N; ++i){
            res[order[i]] = '1' + i;
        }

        return res;
    }
};