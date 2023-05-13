class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        const int N = coins.size();

        // Step 1: create graph G
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        // Step 2: iteratively mark leaf nodes with no coins (and their incident edges)
        //         those leaf nodes don't have any coins => we don't need them
        queue<int> q;
        vector<int> degree(N);
        for(int node = 0; node < N; ++node){
            degree[node] = G[node].size();
            if(degree[node] == 1 && coins[node] == 0){
                q.push(node);
            }
        }
        
        vector<bool> need(N, true);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            need[node] = false;
            
            for(int nextNode: G[node]){
                degree[nextNode] -= 1;
                if(degree[nextNode] == 1 && coins[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        // Step 3: update graph G by removing nodes and edges marked at step 2
        //         in the updated graph G: each leaf node contains one coin
        for(int node = 0; node < N; ++node){
            G[node].clear();
        }

        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            if(need[a] && need[b]){
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }

        // Step 4: remove the leaf nodes of the graph G (in 2 iterations)
        //         the removed leaf nodes will be covered by the remaining nodes of the graph G
        for(int node = 0; node < N; ++node){
            degree[node] = G[node].size();
            if(degree[node] == 1){
                q.push(node);
            }
        }

        for(int iteration = 1; iteration <= 2; ++iteration){
            for(int i = q.size(); i >= 1; --i){
                int node = q.front();
                q.pop();

                need[node] = false;

                for(int nextNode: G[node]){
                    degree[nextNode] -= 1;
                    if(degree[nextNode] == 1){
                        q.push(nextNode);
                    }
                }
            }
        }

        // Step 5: collect the remaining edges of the graph G
        //         update the result (res += 2) for each remaining edge
        //         we add +2 because an edge will be traversed twice
        //         (first time when we move forward from the start node and
        //          second time when we move backward to the start node)
        int res = 0;
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            if(need[a] && need[b]){
                res += 2;
            }
        }
        
        return res;
    }
};