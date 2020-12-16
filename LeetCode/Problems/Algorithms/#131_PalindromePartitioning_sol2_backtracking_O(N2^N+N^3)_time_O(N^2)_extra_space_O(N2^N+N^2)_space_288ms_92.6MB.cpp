class Solution {
private:
    bool isPalindromeChecker(const string& S, const int& L, const int& R){
        for(int i = L, j = R; i < j; ++i, --j){
            if(S[i] != S[j]){
                return false;
            }
        }
        return true;
    }
    
    void back(int prevPos, const string& S, vector<vector<bool>>& isPalindrome, vector<int>& st, vector<vector<string>>& partitions){
        if(prevPos + 1 == S.length()){
            partitions.push_back({});
            for(int i = 1; i < st.size(); ++i){
                partitions.back().push_back(S.substr(st[i - 1] + 1, st[i] - st[i - 1]));
            }
        }else{
            for(int pos = prevPos + 1; pos < S.length(); ++pos){
                if(isPalindrome[prevPos + 1][pos]){
                    st.push_back(pos);
                    back(pos, S, isPalindrome, st, partitions);
                    st.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        const int N = s.length();
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                isPalindrome[i][j] = isPalindromeChecker(s, i, j);
            }
        }
        
        vector<int> st;
        st.push_back(-1);
        vector<vector<string>> partitions;
        back(-1, s, isPalindrome, st, partitions);
        
        return partitions;
    }
};