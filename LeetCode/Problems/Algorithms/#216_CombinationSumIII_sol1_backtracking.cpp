class Solution {
private:
    void back(int level, int sum, vector<int>& st, const int& k, const int& n, vector<vector<int>>& solutions){
        if(level == k){
            if(sum == n){
                solutions.push_back(st);
            }
        }else{
            int last_val = (level > 0 ? st[level - 1] : 0);
            for(int i = last_val + 1; i <= 9; ++i){
                if(sum + i <= n){
                    st[level] = i;
                    back(level + 1, sum + i, st, k, n, solutions);
                }
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> solutions;
        vector<int> st(k);
        
        back(0, 0, st, k, n, solutions);
        
        return solutions;
    }
};