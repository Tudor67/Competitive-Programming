class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;
        vector<vector<int>> g(N);
        vector<int> inDegree(N);
        for(const vector<int>& P: prerequisites){
            g[P[1]].push_back(P[0]);
            inDegree[P[0]] += 1;
        }
        
        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }
        
        vector<int> topSortNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topSortNodes.push_back(node);
            
            for(int nextNode: g[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }
        
        if((int)topSortNodes.size() < N){
            topSortNodes.clear();
        }
        
        return topSortNodes;
    }
};