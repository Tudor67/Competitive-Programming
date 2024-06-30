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
        for(int node = 0; node < N; ++node){
            ancestors[node].push_back(node);
        }

        vector<int> temp;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                temp.clear();
                merge(ancestors[node].begin(), ancestors[node].end(),
                      ancestors[nextNode].begin(), ancestors[nextNode].end(),
                      back_inserter(temp));
                temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
                ancestors[nextNode] = temp;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        for(int node = 0; node < N; ++node){
            ancestors[node].erase(find(ancestors[node].begin(), ancestors[node].end(), node));
        }

        return ancestors;
    }
};