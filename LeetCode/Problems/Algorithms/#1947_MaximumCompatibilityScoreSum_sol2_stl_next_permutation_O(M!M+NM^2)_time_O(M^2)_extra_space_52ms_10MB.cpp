class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const int M = students.size();
        const int N = students[0].size();
        
        vector<vector<int>> compatibilityScore(M, vector<int>(M, 0));
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < M; ++j){
                for(int k = 0; k < N; ++k){
                    compatibilityScore[i][j] += (students[i][k] == mentors[j][k]);
                }
            }
        }
        
        int maxScore = 0;
        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        do{
            int score = 0;
            for(int i = 0; i < M; ++i){
                score += compatibilityScore[p[i]][i];
            }
            maxScore = max(maxScore, score);
        }while(next_permutation(p.begin(), p.end()));
        
        return maxScore;
    }
};