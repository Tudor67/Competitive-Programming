class Solution {
private:
    void back(string& st, const string& S, vector<string>& answer){
        if(st.length() == S.length()){
            answer.push_back(st);
        }else{
            int level = st.size();
            for(char c: set<char>{char(tolower(S[level])), char(toupper(S[level]))}){
                st.push_back(c);
                back(st, S, answer);
                st.pop_back();
            }
        }
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        string st;
        vector<string> answer;
        back(st, S, answer);
        return answer;
    }
};