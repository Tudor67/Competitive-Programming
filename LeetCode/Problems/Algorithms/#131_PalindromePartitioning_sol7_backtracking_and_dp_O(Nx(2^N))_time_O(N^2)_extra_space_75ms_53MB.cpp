class Solution {
private:
    void partition(int startIndex, vector<string>& st, const string& S, vector<vector<string>>& res,
                   vector<vector<bool>>& isPalindrome){
        const int N = S.length();

        if(startIndex == N){
            res.push_back(st);
        }else{
            st.push_back({});
            for(int i = startIndex; i < N; ++i){
                st.back().push_back(S[i]);
                if(isPalindrome[startIndex][i]){
                    partition(i + 1, st, S, res, isPalindrome);
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
                if(s[i] == s[j]){
                    if(len <= 2 || isPalindrome[i + 1][j - 1]){
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }

        vector<string> p;
        vector<vector<string>> res;
        partition(0, p, s, res, isPalindrome);

        return res;
    }
};