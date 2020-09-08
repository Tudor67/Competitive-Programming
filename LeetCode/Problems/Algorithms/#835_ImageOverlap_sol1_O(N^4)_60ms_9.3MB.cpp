class Solution {
private:
    int overlap(const vector<vector<int>>& A, const vector<vector<int>>& B,
                const int& ROW_SHIFT, const int& COL_SHIFT){
        const int N = A.size();
        int overlap_cnt = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(row + ROW_SHIFT < N && col + COL_SHIFT < N){
                    overlap_cnt += (A[row][col] * B[row + ROW_SHIFT][col + COL_SHIFT]);
                }
            }
        }
        return overlap_cnt;
    }
    
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int answer = 0;
        for(int row_shift = 0; row_shift < A.size(); ++row_shift){
            for(int col_shift = 0; col_shift < A.size(); ++col_shift){
                answer = max(overlap(A, B, row_shift, col_shift), answer);
                answer = max(overlap(B, A, row_shift, col_shift), answer);
            }
        }
        return answer;
    }
};