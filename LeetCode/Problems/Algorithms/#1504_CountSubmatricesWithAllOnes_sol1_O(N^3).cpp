class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int N = mat.size();
        const int M = mat[0].size();
        
        vector<vector<int>> height(mat);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(mat[i][j] == 1){
                    height[i][j] += height[i - 1][j];
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                int min_height = height[i][j];
                for(int k = j; min_height > 0 && k >= 0; --k){
                    min_height = min(height[i][k], min_height);
                    answer += min_height;
                }
            }
        }
        
        return answer;
    }
};