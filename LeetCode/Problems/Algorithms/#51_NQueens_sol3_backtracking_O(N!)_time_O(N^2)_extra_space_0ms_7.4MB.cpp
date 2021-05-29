class Solution {
private:
    void back(vector<int>& st, int level, const int& N, int visMaskCol, int visMaskMainDiag, int visMaskSecDiag, vector<vector<string>>& answer){
        if(level == N){
            vector<string> grid(N, string(N, '.'));
            for(int row = 0; row < N; ++row){
                int col = st[row];
                grid[row][col] = 'Q';
            }
            answer.push_back(grid);
        }else{
            int row = level;
            for(int col = 0; col < N; ++col){
                int mainDiag = row - col + N - 1;
                int secDiag = row + col;
                if(!((visMaskCol >> col) & 1) && !((visMaskMainDiag >> mainDiag) & 1) && !((visMaskSecDiag >> secDiag) & 1)){
                    st[level] = col;
                    back(st, level + 1, N, visMaskCol | (1 << col), visMaskMainDiag | (1 << mainDiag), visMaskSecDiag | (1 << secDiag), answer);
                }
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<int> st(n);
        back(st, 0, n, 0, 0, 0, answer);
        return answer;
    }
};