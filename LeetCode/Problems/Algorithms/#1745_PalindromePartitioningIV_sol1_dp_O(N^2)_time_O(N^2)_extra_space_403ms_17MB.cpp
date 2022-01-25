class Solution {
public:
    bool checkPartitioning(string s) {
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
        
        for(int i = 0; i < N; ++i){
            if(isPalindrome[0][i]){
                for(int j = i + 1; j + 1 < N; ++j){
                    if(isPalindrome[i + 1][j] && isPalindrome[j + 1][N - 1]){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};