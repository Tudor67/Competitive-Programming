class Solution {
private:
    void rotate90(vector<vector<int>>& mat){
        const int N = mat.size();

        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i = 0; i < N; ++i){
            reverse(mat[i].begin(), mat[i].end());
        }
    }

public:
    bool findRotation(vector<vector<int>>& originalMat, vector<vector<int>>& target) {
        if(originalMat == target){
            return true;
        }

        vector<vector<int>> mat = originalMat;
        for(int rot = 1; rot <= 3; ++rot){
            rotate90(mat);
            if(mat == target){
                return true;
            }
        }

        return false;
    }
};