class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    void storeConnectedComponentNodes(int srcNode, const Graph& G, vector<int>& connectedComponentNodes){
        vector<bool> vis(G.size(), false);
        queue<int> q;
        q.push(srcNode);
        vis[srcNode] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            connectedComponentNodes.push_back(node);

            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    vis[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }
    }

    int computeNumberOfGroups(int srcNode, const Graph& G){
        vector<int> groupOf(G.size(), INF);
        queue<int> q;
        q.push(srcNode);
        groupOf[srcNode] = 1;

        int maxGroup = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            maxGroup = max(maxGroup, groupOf[node]);

            for(int nextNode: G[node]){
                if(groupOf[nextNode] == INF){
                    groupOf[nextNode] = groupOf[node] + 1;
                    q.push(nextNode);
                }else if(abs(groupOf[nextNode] - groupOf[node]) != 1){
                    return INF;
                }
            }
        }

        return maxGroup;
    }

public:
    int magnificentSets(int N, vector<vector<int>>& edges) {
        Graph G(N + 1);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int res = 0;
        vector<bool> checked(N + 1, false);
        for(int node = 1; node <= N; ++node){
            if(!checked[node]){
                vector<int> connectedComponentNodes;
                storeConnectedComponentNodes(node, G, connectedComponentNodes);

                int maxNumberOfGroups = 0;
                for(int srcNode: connectedComponentNodes){
                    maxNumberOfGroups = max(maxNumberOfGroups, computeNumberOfGroups(srcNode, G));
                    checked[srcNode] = true;
                    if(maxNumberOfGroups == INF){
                        return -1;
                    }
                }

                res += maxNumberOfGroups;
            }
        }
        
        return res;
    }
};