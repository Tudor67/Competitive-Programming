class Solution {
public:
    vector<int> sortItems(int N, int M, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: each node with (group[node] == -1) should be seen as a node of a separate group
        //         create new group for each node with (group[node] == -1)
        int newGroupIndex = M - 1;
        for(int node = 0; node < N; ++node){
            if(group[node] == -1){
                newGroupIndex += 1;
                group[node] = newGroupIndex;
            }
        }
        const int TOTAL_GROUPS = newGroupIndex + 1;

        // Step 2: create graph `G` by adding virtual nodes for each group of nodes
        //         (N + g)th node corresponds to the gth group (in node)
        //         (N + TOTAL_GROUPS + g) node corresponds to the gth group (out node)
        //         arcs related to virtual nodes:
        //              each virtual (in) node (N + g) will have arcs to the nodes of the gth group
        //              each normal node of the gth group will have arcs to virtual (out) node (N + TOTAL_GROUPS + g)
        //         arcs related to normal nodes:
        //              add arcs from normal nodes to normal nodes (when we have the same group)
        //              add arcs from corresponding virtual (out) nodes to virtual (in) nodes (when we have different groups)
        using Graph = vector<vector<int>>;
        Graph G(N + 2 * TOTAL_GROUPS);
        for(int node = 0; node < N; ++node){
            G[N + group[node]].push_back(node);
            G[node].push_back(N + TOTAL_GROUPS + group[node]);
            for(int beforeNode: beforeItems[node]){
                if(group[beforeNode] == group[node]){
                    G[beforeNode].push_back(node);
                }else{
                    G[N + TOTAL_GROUPS + group[beforeNode]].push_back(N + group[node]);
                }
            }
        }

        // Step 3: run topological sort on graph `G` starting from virtual (in) nodes (separately for each valid (in) node)
        //         store only the normal nodes (we don't need auxiliary virtual nodes)
        vector<int> inDegree(N + 2 * TOTAL_GROUPS);
        for(int node = 0; node < N + 2 * TOTAL_GROUPS; ++node){
            for(int nextNode: G[node]){
                inDegree[nextNode] += 1;
            }
        }

        vector<int> res;
        vector<bool> vis(N + TOTAL_GROUPS, false);
        queue<int> q;
        for(int node = N; node < N + TOTAL_GROUPS; ++node){
            if(inDegree[node] == 0 && !vis[node]){
                q.push(node);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    if(node < N){
                        res.push_back(node);
                    }
                    if(node < N + TOTAL_GROUPS){
                        vis[node] = true;
                    }

                    for(int nextNode: G[node]){
                        inDegree[nextNode] -= 1;
                        if(inDegree[nextNode] == 0){
                            q.push(nextNode);
                        }
                    }
                }
            }
        }

        // Step 4: if the res vector doesn't contain all the nodes of the graph `G` => return {}
        if((int)res.size() != N){
            res.clear();
        }

        // Step 5: restore the initial group values of the nodes
        for(int node = 0; node < N; ++node){
            if(group[node] >= M){
                group[node] = -1;
            }
        }

        return res;
    }
};