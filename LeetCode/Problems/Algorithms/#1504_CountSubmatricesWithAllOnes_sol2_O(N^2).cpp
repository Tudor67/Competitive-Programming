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
            stack<int> st;
            vector<int> cnt(M);
            for(int j = 0; j < M; ++j){
                while(!st.empty() && height[i][st.top()] >= height[i][j]){
                    st.pop();
                }
                // update the number of submatrices (with ones) that end in pos (i, j)
                if(st.empty()){
                    cnt[j] = height[i][j] * (j + 1);
                }else{
                    int prev_j = st.top();
                    cnt[j] = cnt[prev_j] + height[i][j] * (j - prev_j);
                }
                answer += cnt[j];
                st.push(j);
            }
        }
        
        return answer;
    }
};