class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        const int ROWS = score.size();
        const int COLS = score[0].size();
        
        int maxScore = 0;
        for(int row = 0; row < ROWS; ++row){
            maxScore = max(maxScore, score[row][k]);
        }

        vector<int> scoreToRow(maxScore + 1, -1);
        for(int row = 0; row < ROWS; ++row){
            scoreToRow[score[row][k]] = row;
        }

        int index = 0;
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int currentScore = maxScore; currentScore >= 0; --currentScore){
            int row = scoreToRow[currentScore];
            if(row >= 0){
                res[index] = score[row];
                index += 1;
            }
        }

        return res;
    }
};