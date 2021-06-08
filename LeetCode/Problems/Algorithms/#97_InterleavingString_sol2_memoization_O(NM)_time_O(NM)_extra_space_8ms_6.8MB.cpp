class Solution {
private:
    bool prefixMatch(const string& S1, const int& LEN1, const string& S2, const int& LEN2){
        if(LEN1 != LEN2){
            return false;
        }
        for(int i = 0; i < LEN1; ++i){
            if(S1[i] != S2[i]){
                return false;
            }
        }
        return true;
    }
    
    bool solve(const string& S1, int pos1, const string& S2, int pos2, const string& S3, int pos3,
               vector<vector<bool>>& vis, vector<vector<bool>>& memo){
        bool sol = false;
        if(vis[pos1 + 1][pos2 + 1]){
            sol = memo[pos1 + 1][pos2 + 1];
        }else if(pos1 + pos2 + 1 != pos3){
            sol = false;
        }else if(pos1 == -1 && pos2 == -1){
            sol = (pos3 == -1);
        }else if(pos1 == -1){
            sol = prefixMatch(S2, pos2 + 1, S3, pos3 + 1);
        }else if(pos2 == -1){
            sol = prefixMatch(S1, pos1 + 1, S3, pos3 + 1);
        }else{
            sol = (S1[pos1] == S3[pos3] && solve(S1, pos1 - 1, S2, pos2, S3, pos3 - 1, vis, memo))
                    ||
                  (S2[pos2] == S3[pos3] && solve(S1, pos1, S2, pos2 - 1, S3, pos3 - 1, vis, memo));
        }
        vis[pos1 + 1][pos2 + 1] = true;
        memo[pos1 + 1][pos2 + 1] = sol;
        return sol;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int N3 = s3.length();
        vector<vector<bool>> vis(N1 + 1, vector<bool>(N2 + 1, false));
        vector<vector<bool>> memo(N1 + 1, vector<bool>(N2 + 1, false));
        return solve(s1, N1 - 1, s2, N2 - 1, s3, N3 - 1, vis, memo);
    }
};