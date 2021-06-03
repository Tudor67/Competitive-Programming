class Solution {
public:
    int countSubstrings(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        // leftMax[i][j]  - max length of matching substrings s[..i] and t[..j]
        // rightMax[i][j] - max length of matching substrings s[i..] and t[j..]
        vector<vector<int>> leftMax(N, vector<int>(M));
        vector<vector<int>> rightMax(N, vector<int>(M));
        
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(s[i] == t[j]){
                    leftMax[i][j] = 1 + (i > 0 && j > 0 ? leftMax[i - 1][j - 1] : 0);
                }
            }
        }
        
        for(int i = N - 1; i >= 0; --i){
            for(int j = M - 1; j >= 0; --j){
                if(s[i] == t[j]){
                    rightMax[i][j] = 1 + (i < N - 1 && j < M - 1 ? rightMax[i + 1][j + 1] : 0);
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(s[i] != t[j]){
                    int leftCnt = (i > 0 && j > 0 ? leftMax[i - 1][j - 1] : 0);
                    int rightCnt = (i < N - 1 && j < M - 1 ? rightMax[i + 1][j + 1] : 0);
                    answer += (leftCnt + 1) * (rightCnt + 1);
                }
            }
        }
        
        return answer;
    }
};