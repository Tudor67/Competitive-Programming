class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        // Step 1: create isBanned vector
        vector<bool> isBanned(n, false);
        for(int node: banned){
            isBanned[node] = true;
        }

        // Step 2: create graph G
        vector<vector<int>> G(n);
        for(int startNode = 0; startNode + k - 1 < n; ++startNode){
            for(int a = startNode, b = startNode + k - 1; a < b; ++a, --b){
                if(!isBanned[a] && !isBanned[b]){
                    G[a].push_back(b);
                    G[b].push_back(a);
                }
            }
        }

        // Step 3: bfs from node p
        vector<int> res(n, -1);
        queue<int> q;
        q.push(p);
        res[p] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(res[nextNode] == -1){
                    res[nextNode] = res[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return res;
    }
};