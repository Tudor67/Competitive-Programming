class Solution {
private:
    void back(int i, const string& S, vector<string>& st, vector<vector<bool>>& isPalindrome, vector<vector<string>>& palindromes){
        const int N = S.length();
        if(i == N){
            palindromes.push_back(st);
        }else{
            st.push_back("");
            for(int j = i; j < N; ++j){
                st.back() += S[j];
                if(isPalindrome[i][j]){
                    back(j + 1, S, st, isPalindrome, palindromes);
                }
            }
            st.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        const int N = s.length();
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j] && (i + 1 > j - 1 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                }
            }
        }
        
        vector<string> st;
        vector<vector<string>> palindromes;
        back(0, s, st, isPalindrome, palindromes);
        
        return palindromes;
    }
};