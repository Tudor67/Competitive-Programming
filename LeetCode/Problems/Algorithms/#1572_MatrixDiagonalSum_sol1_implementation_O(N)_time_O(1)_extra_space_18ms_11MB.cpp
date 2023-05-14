class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int N = mat.size();

        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += mat[i][i];
            if(i != N - 1 - i){
                sum += mat[i][N - 1 - i];
            }
        }

        return sum;
    }
};