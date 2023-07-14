class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;

        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(const vector<int>& P: prerequisites){
            int a = P[0];
            int b = P[1];
            G[b].push_back(a);
            inDegree[a] += 1;
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        return (count(inDegree.begin(), inDegree.end(), 0) == N);
    }
};