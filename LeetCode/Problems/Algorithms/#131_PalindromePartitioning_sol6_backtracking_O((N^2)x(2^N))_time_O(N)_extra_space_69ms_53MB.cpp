class Solution {
private:
    bool isPalindrome(const string& S, int l, int r){
        while(l < r){
            if(S[l] == S[r]){
                l += 1;
                r -= 1;
            }else{
                return false;
            }
        }
        return true;
    }

    void partition(int startIndex, vector<string>& st, const string& S, vector<vector<string>>& res){
        const int N = S.length();

        if(startIndex == N){
            res.push_back(st);
        }else{
            st.push_back({});
            for(int i = startIndex; i < N; ++i){
                st.back().push_back(S[i]);
                if(isPalindrome(S, startIndex, i)){
                    partition(i + 1, st, S, res);
                }
            }
            st.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        const int N = s.length();

        vector<string> p;
        vector<vector<string>> res;
        partition(0, p, s, res);

        return res;
    }
};