class Solution {
private:
    void back(int k, string& st, const string& S, vector<string>& ans){
        if(k == S.length()){
            ans.push_back(st);
        }else{
            for(char c: set<char>{char(tolower(S[k])), char(toupper(S[k]))}){
                st[k] = c;
                back(k + 1, st, S, ans);
            }
        }
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string st = S;
        back(0, st, S, ans);
        return ans;
    }
};