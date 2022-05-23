class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int N = scores.size();
        const int E = edges.size();
        
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        for(int node = 0; node < N; ++node){
            partial_sort(G[node].begin(), G[node].begin() + min(3, (int)G[node].size()), G[node].end(),
                 [&](const int& LHS, const int& RHS){
                     return (scores[LHS] > scores[RHS]);
                 });
        }
        
        int maxScore = -1;
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            for(int i = 0; i < min(3, (int)G[x].size()); ++i){
                for(int j = 0; j < min(3, (int)G[y].size()); ++j){
                    int a = G[x][i];
                    int b = G[y][j];
                    if(a != y && a != b && b != x){
                        int score = scores[a] + scores[x] + scores[y] + scores[b];
                        maxScore = max(maxScore, score);
                    }
                }
            }
        }
        
        return maxScore;
    }
};