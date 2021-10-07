class Solution {
private:
    int computeMaxScore(int studentIdx, int maskFreeMentors, const int& M, vector<vector<int>>& compatibilityScore, vector<int>& memo){
        if(maskFreeMentors == 0 || studentIdx < 0 || M <= studentIdx){
            return 0;
        }
        if(memo[maskFreeMentors] != -1){
            return memo[maskFreeMentors];
        }
        int maxScore = 0;
        for(int mentorIdx = 0; mentorIdx < M; ++mentorIdx){
            if((maskFreeMentors >> mentorIdx) & 1){
                int score = compatibilityScore[studentIdx][mentorIdx] +
                            computeMaxScore(studentIdx - 1, maskFreeMentors ^ (1 << mentorIdx), M, compatibilityScore, memo);
                maxScore = max(maxScore, score);
            }
        }
        memo[maskFreeMentors] = maxScore;
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
        
        vector<int> memo(FULL_MASK + 1, -1);
        return computeMaxScore(M - 1, FULL_MASK, M, compatibilityScore, memo);
    }
};