class Solution {
private:
    bool is_palindrome(const string& s, const int& start_pos, const int& end_pos){
        for(int i = start_pos, j = end_pos; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    
    void back(int k, vector<int>& st, const string& s, const int& n, vector<vector<string>>& ans){
        if(st[k - 1] == n - 1){
            ans.push_back(vector<string>());
            for(int i = 1; i <= k - 1; ++i){
                ans.back().push_back(s.substr(st[i - 1] + 1, st[i] - st[i - 1]));
            }
        }else{
            for(int i = st[k - 1] + 1; i <= n - 1; ++i){
                if(is_palindrome(s, st[k - 1] + 1, i)){
                    st[k] = i;
                    back(k + 1, st, s, n, ans);
                }
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<int> st(n + 1);
        vector<vector<string>> ans;
        
        st[0] = -1;
        back(1, st, s, n, ans);
        
        return ans;
    }
};