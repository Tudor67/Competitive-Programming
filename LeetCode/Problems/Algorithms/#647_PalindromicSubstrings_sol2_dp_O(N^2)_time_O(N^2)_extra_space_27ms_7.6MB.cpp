class Solution {
public:
    int countSubstrings(string s) {
        const int N = s.length();
        
        int res = 0;
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(i + 1 >= j - 1 || isPalindrome[i + 1][j - 1]){
                        isPalindrome[i][j] = true;
                        res += 1;
                    }
                }
            }
        }
        
        return res;
    }
};