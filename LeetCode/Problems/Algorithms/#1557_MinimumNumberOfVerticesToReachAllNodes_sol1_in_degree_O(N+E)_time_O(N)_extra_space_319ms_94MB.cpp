class Solution {
public:
    vector<int> findSmallestSetOfVertices(int N, vector<vector<int>>& edges) {
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            inDegree[b] += 1;
        }

        vector<int> res;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                res.push_back(node);
            }
        }

        return res;
    }
};