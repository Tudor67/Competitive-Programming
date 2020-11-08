class Solution {
public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> neighbors(N);
        for(const vector<int>& EDGE: edges){
            neighbors[EDGE[0]].insert(EDGE[1]);
            neighbors[EDGE[1]].insert(EDGE[0]);
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(neighbors[node].size() == 1){
                q.push(node);
            }
        }
        
        int remainingNodes = N;
        while(remainingNodes > 2){
            int fixedSize = q.size();
            remainingNodes -= fixedSize;
            for(int i = 0; i < fixedSize; ++i){
                int node = q.front();
                int neighbor = *(neighbors[node].begin());
                q.pop();

                neighbors[node].erase(neighbor);
                neighbors[neighbor].erase(node);

                if(neighbors[neighbor].size() == 1){
                    q.push(neighbor);
                }
            }
        }
        
        vector<int> centroids;
        while(!q.empty()){
            centroids.push_back(q.front());
            q.pop();
        }
        
        if(N == 1){
            centroids.push_back(0);
        }
        
        return centroids;
    }
};