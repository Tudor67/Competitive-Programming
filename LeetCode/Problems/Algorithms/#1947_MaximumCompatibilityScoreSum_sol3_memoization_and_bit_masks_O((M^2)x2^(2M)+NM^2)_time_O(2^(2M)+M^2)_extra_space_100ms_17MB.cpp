class Solution {
private:
    int computeMaxScore(int visMaskStudents, int visMaskMentors, const int& FULL_MASK, const int& M,
                        vector<vector<int>>& compatibilityScore, vector<vector<int>>& memo){
        if(visMaskStudents == FULL_MASK){
            return 0;
        }
        if(memo[visMaskStudents][visMaskMentors] != -1){
            return memo[visMaskStudents][visMaskMentors];
        }
        int maxScore = 0;
        for(int studentIdx = 0; studentIdx < M; ++studentIdx){
            if(!((visMaskStudents >> studentIdx) & 1)){
                for(int mentorIdx = 0; mentorIdx < M; ++mentorIdx){
                    if(!((visMaskMentors >> mentorIdx) & 1)){
                        int score = compatibilityScore[studentIdx][mentorIdx] +
                                    computeMaxScore(visMaskStudents | (1 << studentIdx), visMaskMentors | (1 << mentorIdx), FULL_MASK, M,
                                                    compatibilityScore, memo);
                        maxScore = max(maxScore, score);
                    }
                }
            }
        }
        memo[visMaskStudents][visMaskMentors] = maxScore;
        return maxScore;
    }
    
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const int M = students.size();
        const int N = students[0].size();
        const int FULL_MASK = (1 << M) - 1;
        
        vector<vector<int>> compatibilityScore(M, vector<int>(M, 0));
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < M; ++j){
                for(int k = 0; k < N; ++k){
                    compatibilityScore[i][j] += (students[i][k] == mentors[j][k]);
                }
            }
        }
        
        vector<vector<int>> memo(FULL_MASK + 1, vector<int>(FULL_MASK + 1, -1));
        return computeMaxScore(0, 0, FULL_MASK, M, compatibilityScore, memo);
    }
};