class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> outDegree(N + 1);
        vector<int> inDegree(N + 1);
        for(const vector<int>& T: trust){
            int a = T[0];
            int b = T[1];
            outDegree[a] += 1;
            inDegree[b] += 1;
        }

        for(int node = 1; node <= N; ++node){
            if(outDegree[node] == 0 && inDegree[node] == N - 1){
                return node;
            }
        }

        return -1;
    }
};