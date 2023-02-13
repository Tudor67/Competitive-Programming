class Solution {
private:
    using Graph = vector<vector<int>>;

    void updateFirstAndSecondMax(const pair<long long, int>& P, vector<pair<long long, int>>& s){
        if(P > s[0]){
            s[1] = s[0];
            s[0] = P;
        }else if(P > s[1]){
            s[1] = P;
        }
    }
    
    void dfs(int parentNode, int node, const Graph& G, vector<int>& price,
             vector<vector<pair<long long, int>>>& s0, vector<vector<pair<long long, int>>>& s1){
        bool isLeaf = true;

        for(int childNode: G[node]){
            if(childNode != parentNode){
                isLeaf = false;

                dfs(node, childNode, G, price, s0, s1);

                s0[childNode][0].second = childNode;
                s1[childNode][0].second = childNode;

                updateFirstAndSecondMax(s0[childNode][0], s0[node]);
                updateFirstAndSecondMax(s1[childNode][0], s1[node]);
            }
        }

        if(!isLeaf){
            s0[node][0].first += price[node];
            s0[node][1].first += price[node];
        }
        s1[node][0].first += price[node];
        s1[node][1].first += price[node];
    }
    
public:
    long long maxOutput(int N, vector<vector<int>>& edges, vector<int>& price) {        
        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // s0[node]: max path sums from root to a leaf (leaf is not included)
        //           when node is the root of the tree
        // s1[node]: max path sums from root to a leaf (leaf is included)
        //           when node is the root of the tree
        vector<vector<pair<long long, int>>> s0(N, vector<pair<long long, int>>(2, {0, -1}));
        vector<vector<pair<long long, int>>> s1(N, vector<pair<long long, int>>(2, {0, -1}));
        dfs(-1, 0, G, price, s0, s1);

        long long res = 0;
        for(int node = 0; node < N; ++node){
            res = max(res, s0[node][0].first);               // s0 leaf is the root
            res = max(res, s1[node][0].first - price[node]); // node is the root
            for(int i = 0; i < 2; ++i){
                for(int j = 0; j < 2; ++j){
                    if(s0[node][i].second != s1[node][j].second &&
                       s0[node][i].second != -1 && s1[node][j].second != -1){
                        res = max(res, s0[node][i].first + s1[node][j].first - price[node]); // s0 leaf is the root
                    }
                }
            }
        }
        
        return res;
    }
};