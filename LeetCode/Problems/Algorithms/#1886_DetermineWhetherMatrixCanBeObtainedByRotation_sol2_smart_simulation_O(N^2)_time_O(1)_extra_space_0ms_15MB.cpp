class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int N = mat.size();

        vector<bool> ok(4, true);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                ok[0] = ok[0] && (mat[i][j] == target[i][j]);
                ok[1] = ok[1] && (mat[N - 1 - j][i] == target[i][j]);
                ok[2] = ok[2] && (mat[N - 1 - i][N - 1 - j] == target[i][j]);
                ok[3] = ok[3] && (mat[j][N - 1 - i] == target[i][j]);
            }
        }

        return (find(ok.begin(), ok.end(), true) != ok.end());
    }
};