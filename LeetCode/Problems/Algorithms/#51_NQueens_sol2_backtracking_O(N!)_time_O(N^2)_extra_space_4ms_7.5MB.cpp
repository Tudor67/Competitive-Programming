class Solution {
private:
    void back(vector<int>& st, int level, const int& N, vector<bool>& visCol,
              vector<bool>& visMainDiag, vector<bool>& visSecDiag, vector<vector<string>>& answer){
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
                if(!visCol[col] && !visMainDiag[mainDiag] && !visSecDiag[secDiag]){
                    st[level] = col;
                    visCol[col] = true;
                    visMainDiag[mainDiag] = true;
                    visSecDiag[secDiag] = true;
                    back(st, level + 1, N, visCol, visMainDiag, visSecDiag, answer);
                    visMainDiag[mainDiag] = false;
                    visSecDiag[secDiag] = false;
                    visCol[col] = false;
                }
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<int> st(n);
        vector<bool> visCol(n, false);
        vector<bool> visMainDiag(2 * n, false);
        vector<bool> visSecDiag(2 * n, false);
        back(st, 0, n, visCol, visMainDiag, visSecDiag, answer);
        return answer;
    }
};