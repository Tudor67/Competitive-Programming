class Solution {    
public:
    int minCut(string s) {
        const int N = s.length();
        
        // isPalindrome[i][j]: true,  if s[i .. j] is a palindrome
        //                     false, otherwise
        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            isPalindrome[i][i] = true;
        }
        
        for(int len = 2; len <= N; ++len){
            for(int i = 0, j = i + len - 1; j < N; ++i, ++j){
                if(s[i] == s[j]){
                    if(i + 1 == j || isPalindrome[i + 1][j - 1]){
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
        
        // minCuts[i]: minimum cuts needed for a palindrome partitioning of s[0 .. i]
        vector<int> minCuts(N);
        for(int i = 0; i < N; ++i){
            minCuts[i] = i;
            for(int j = 0; j <= i; ++j){
                if(isPalindrome[j][i]){
                    if(j == 0){
                        minCuts[i] = 0;
                    }else{
                        minCuts[i] = min(minCuts[i], 1 + minCuts[j - 1]);
                    }
                }
            }
        }
        
        return minCuts[N - 1];
    }
};