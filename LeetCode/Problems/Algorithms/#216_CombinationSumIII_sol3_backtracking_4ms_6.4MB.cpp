class Solution {
private:
    void back(int level, int sum, int targetSum, vector<int>& st, vector<vector<int>>& res){
        if(level == (int)st.size()){
            if(sum == targetSum){
                res.push_back(st);
            }
        }else{
            int startDigit = (level == 0 ? 1 : st[level - 1] + 1);
            for(int digit = startDigit; digit <= 9 && sum + digit <= targetSum; ++digit){
                st[level] = digit;
                back(level + 1, sum + digit, targetSum, st, res);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> st(k);
        vector<vector<int>> res;
        back(0, 0, n, st, res);
        return res;
    }
};