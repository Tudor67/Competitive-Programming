class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        const int N = lcp.size();
        const char SPECIAL_CHAR = '*';
        const char MIN_VALID_CHAR = 'a';
        const char MAX_VALID_CHAR = 'z';

        string s(N, SPECIAL_CHAR);
        char candidateChar = MIN_VALID_CHAR;

        for(int i = 0; i < N; ++i){
            if(s[i] == SPECIAL_CHAR){
                s[i] = candidateChar;
                candidateChar += 1;

                for(int j = i + 1; j < N; ++j){
                    if(lcp[i][j] > 0){
                        s[j] = s[i];
                    }
                }
            }

            if(s[i] > MAX_VALID_CHAR){
                return "";
            }
        }

        vector<vector<int>> currLCP(N + 1, vector<int>(N + 1));
        for(int i = N - 1; i >= 0; --i){
            for(int j = N - 1; j >= 0; --j){
                if(s[i] == s[j]){
                    currLCP[i][j] = 1 + currLCP[i + 1][j + 1];
                }
                
                if(currLCP[i][j] != lcp[i][j]){
                    return "";
                }
            }
        }

        return s;
    }
};