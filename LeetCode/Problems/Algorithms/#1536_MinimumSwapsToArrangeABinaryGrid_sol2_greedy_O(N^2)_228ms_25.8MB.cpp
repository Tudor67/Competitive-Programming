class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        vector<int> suf_zeros(N, 0);
        for(int row = 0; row < N; ++row){
            for(int col = N - 1; col >= 0 && grid[row][col] == 0; --col){
                suf_zeros[row] += 1;
            }
        }
        
        int answer = 0;
        for(int fixed_row = 0; answer != -1 && fixed_row < N; ++fixed_row){
            int min_suf_zeros = N - 1 - fixed_row;
            int best_row = -1;
            
            for(int row = fixed_row; row < N; ++row){
                if(suf_zeros[row] >= min_suf_zeros){
                    best_row = row;
                    break;
                }
            }

            if(best_row == -1){
                answer = -1;
            }else{
                for(int row = best_row; row > fixed_row; --row){
                    suf_zeros[row] = suf_zeros[row - 1];
                    answer += 1;
                }
            }
        }
        
        return answer;
    }
};