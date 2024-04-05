class Solution {
public:
    int findChampion(int N, vector<vector<int>>& edges) {
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            int b = EDGE[1];
            inDegree[b] += 1;
        }

        int champion = -1;
        int championsCount = 0;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                champion = node;
                championsCount += 1;
            }
        }

        if(championsCount >= 2){
            champion = -1;
        }

        return champion;
    }
};