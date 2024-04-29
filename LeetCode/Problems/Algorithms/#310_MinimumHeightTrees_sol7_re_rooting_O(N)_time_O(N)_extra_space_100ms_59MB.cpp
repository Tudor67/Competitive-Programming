class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parent, int node, vector<int>& subtreeHeight, const Graph& G){
        for(int nextNode: G[node]){
            if(nextNode != parent){
                dfs(node, nextNode, subtreeHeight, G);
                subtreeHeight[node] = max(subtreeHeight[node], 1 + subtreeHeight[nextNode]);
            }
        }
    }

    void rerooting(int parent, int node, vector<int>& subtreeHeight, vector<int>& treeHeight, const Graph& G){
        pair<int, int> max1 = {-1, -1};
        pair<int, int> max2 = {-1, -1};
        for(int nextNode: G[node]){
            pair<int, int> p = {subtreeHeight[nextNode], nextNode};
            if(p > max1){
                max2 = max1;
                max1 = p;
            }else if(p > max2){
                max2 = p;
            }
        }

        treeHeight[node] = 1 + max1.first;

        for(int nextNode: G[node]){
            if(nextNode != parent){
                if(nextNode == max1.second){
                    subtreeHeight[node] = 1 + max2.first;
                }else{
                    subtreeHeight[node] = 1 + max1.first;
                }
                rerooting(node, nextNode, subtreeHeight, treeHeight, G);
            }
        }
    }

public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> subtreeHeight(N);
        dfs(-1, 0, subtreeHeight, G);

        vector<int> treeHeight(N);
        rerooting(-1, 0, subtreeHeight, treeHeight, G);

        vector<int> res;
        int minHeight = *min_element(treeHeight.begin(), treeHeight.end());
        for(int node = 0; node < N; ++node){
            if(treeHeight[node] == minHeight){
                res.push_back(node);
            }
        }

        return res;
    }
};