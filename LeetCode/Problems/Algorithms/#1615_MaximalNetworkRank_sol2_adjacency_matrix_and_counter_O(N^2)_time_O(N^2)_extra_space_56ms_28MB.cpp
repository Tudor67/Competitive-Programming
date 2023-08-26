class Solution {
public:
    int maximalNetworkRank(int N, vector<vector<int>>& roads) {
        vector<vector<bool>> isAdj(N, vector<bool>(N, false));
        vector<int> roadsCount(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            isAdj[a][b] = true;
            isAdj[b][a] = true;
            roadsCount[a] += 1;
            roadsCount[b] += 1;
        }

        int res = 0;
        for(int a = 0; a < N; ++a){
            for(int b = a + 1; b < N; ++b){
                int rank = roadsCount[a] + roadsCount[b] - (int)isAdj[a][b];
                res = max(res, rank);
            }
        }

        return res;
    }
};