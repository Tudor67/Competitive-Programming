class Solution {
private:
    vector<string> solutions;
    
    void back(int k, int op_cnt, int cl_cnt, string& cur_sol, const int& n){
        if(op_cnt + cl_cnt == 2 * n){
            solutions.push_back(cur_sol);
        }else{
            if(op_cnt < n){
                cur_sol[k] = '(';
                back(k + 1, op_cnt + 1, cl_cnt, cur_sol, n);
            }
            if(cl_cnt < op_cnt){
                cur_sol[k] = ')';
                back(k + 1, op_cnt, cl_cnt + 1, cur_sol, n);
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        solutions.clear();
        string cur_sol(2 * n, ' ');
        back(0, 0, 0, cur_sol, n);
        return solutions;
    }
};