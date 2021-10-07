class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const int M = students.size();
        const int N = students[0].size();
        
        int maxScore = 0;
        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        do{
            int score = 0;
            for(int i = 0; i < M; ++i){
                for(int j = 0; j < N; ++j){
                    score += (students[p[i]][j] == mentors[i][j]);
                }
            }
            maxScore = max(maxScore, score);
        }while(next_permutation(p.begin(), p.end()));
        
        return maxScore;
    }
};