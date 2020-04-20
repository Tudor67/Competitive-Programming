class Solution {
private:
    void back(int k, const int& n,
              vector<bool>& vis_col, vector<bool>& vis_main_diag, vector<bool>& vis_second_diag,
              vector<short int>& pos, int& sol_cnt){
        if(k == n + 1){
            ++sol_cnt;
        }else{
            for(int i = 1; i <= n; ++i){
                int main_diag_idx = k + i - 1;
                int second_diag_idx = k - i + n;
                
                if(!vis_col[i] && !vis_main_diag[main_diag_idx] && !vis_second_diag[second_diag_idx]){
                    pos[k] = i;
                    vis_col[i] = 1;
                    vis_main_diag[main_diag_idx] = 1;
                    vis_second_diag[second_diag_idx] = 1;
                    
                    back(k + 1, n, vis_col, vis_main_diag, vis_second_diag, pos, sol_cnt);
                    
                    vis_col[i] = 0;
                    vis_main_diag[main_diag_idx] = 0;
                    vis_second_diag[second_diag_idx] = 0;
                }
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        vector<bool> vis_col(n + 1, false);
        vector<bool> vis_main_diag(2 * n, false);
        vector<bool> vis_second_diag(2 * n, false);
        vector<short int> pos(n + 1);
        int sol_cnt = 0;
        
        back(1, n, vis_col, vis_main_diag, vis_second_diag, pos, sol_cnt);
        
        return sol_cnt;
    }
};