class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();
        int answer = 0;
        
        for(int fixed_row = 0; answer != -1 && fixed_row < N; ++fixed_row){
            int min_suf_zeros = N - 1 - fixed_row;
            int best_row = -1;

            for(int row = fixed_row; row < N; ++row){
                int suf_zeros = 0;
                for(int col = N - 1; col >= 0 && grid[row][col] == 0; --col){
                    suf_zeros += 1;
                }

                if(suf_zeros >= min_suf_zeros){
                    best_row = row;
                    break;
                }
            }

            if(best_row == -1){
                answer = -1;
            }else{
                vector<int> temp = grid[best_row];
                for(int row = best_row; row > fixed_row; --row){
                    grid[row] = grid[row - 1];
                    answer += 1;
                }
                grid[fixed_row] = temp;
            }
        }
        
        return answer;
    }
};