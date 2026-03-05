class Solution {
private:
    using Graph = vector<vector<int>>;

    int getCostTo(int to){
        return 2 - (to % 2);
    }

    void updateMax(pair<int, int>& max1, pair<int, int>& max2, const pair<int, int>& p){
        if(max1 <= p){
            max2 = max1;
            max1 = p;
        }else if(max2 <= p){
            max2 = p;
        }
    }

    void dfs(int parent, int node, const Graph& G, vector<pair<int, int>>& max1, vector<pair<int, int>>& max2){
        for(int child: G[node]){
            if(child != parent){
                dfs(node, child, G, max1, max2);
                updateMax(max1[node], max2[node], {getCostTo(child) + max1[child].first, child});
            }
        }
    }

    void rerooting(int parent, int node, const Graph& G, vector<pair<int, int>>& max1, vector<pair<int, int>>& max2, vector<int>& times){
        if(parent != -1){
            if(max1[parent].second == node){
                updateMax(max1[node], max2[node], {getCostTo(parent) + max2[parent].first, parent});
            }else{
                updateMax(max1[node], max2[node], {getCostTo(parent) + max1[parent].first, parent});
            }
        }

        times[node] = max1[node].first;
        
        for(int child: G[node]){
            if(child != parent){
                rerooting(node, child, G, max1, max2, times);
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

        vector<pair<int, int>> max1(N);
        vector<pair<int, int>> max2(N);
        dfs(-1, 0, G, max1, max2);

        vector<int> times(N);
        rerooting(-1, 0, G, max1, max2, times);

        return times;
    }
};