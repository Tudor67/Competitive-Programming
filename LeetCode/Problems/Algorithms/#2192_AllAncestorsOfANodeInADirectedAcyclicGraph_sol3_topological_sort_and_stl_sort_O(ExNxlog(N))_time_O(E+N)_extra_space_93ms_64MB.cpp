class Solution {
public:
    vector<vector<int>> getAncestors(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            inDegree[b] += 1;
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<vector<int>> ancestors(N);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                ancestors[nextNode].push_back(node);
                copy(ancestors[node].begin(), ancestors[node].end(), back_inserter(ancestors[nextNode]));
                sort(ancestors[nextNode].begin(), ancestors[nextNode].end());
                ancestors[nextNode].resize(unique(ancestors[nextNode].begin(), ancestors[nextNode].end())
                                           - ancestors[nextNode].begin());
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        return ancestors;
    }
};