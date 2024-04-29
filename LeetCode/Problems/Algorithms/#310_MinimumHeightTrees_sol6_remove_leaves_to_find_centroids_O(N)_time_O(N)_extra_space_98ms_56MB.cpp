class Solution {
public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        queue<int> q;
        vector<int> degree(N);
        for(int node = 0; node < N; ++node){
            degree[node] = G[node].size();
            if(degree[node] <= 1){
                q.push(node);
            }
        }

        int remainingNodes = N;
        while(remainingNodes >= 3){
            for(int i = q.size(); i >= 1; --i){
                int node = q.front();
                q.pop();

                remainingNodes -= 1;

                for(int nextNode: G[node]){
                    degree[nextNode] -= 1;
                    if(degree[nextNode] == 1){
                        q.push(nextNode);
                    }
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);
        }

        return res;
    }
};