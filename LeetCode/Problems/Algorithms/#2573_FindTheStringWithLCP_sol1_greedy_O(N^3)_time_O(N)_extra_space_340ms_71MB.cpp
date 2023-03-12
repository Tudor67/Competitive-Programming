class Solution {
private:
    bool satisfiesLCP(string& s, int i, int j, vector<vector<int>>& lcp){
        const int N = s.length();
        return (max(i, j) + lcp[i][j] - 1 < N) && // is valid length
               (max(i, j) + lcp[i][j] == N || s[i + lcp[i][j]] != s[j + lcp[i][j]]) && // match <= lcp[i][j]
               (equal(s.begin() + i, s.begin() + i + lcp[i][j], s.begin() + j));       // match == lcp[i][j]
    }

public:
    string findTheString(vector<vector<int>>& lcp) {
        const int N = lcp.size();

        // Step 1: try to build the result s
        string s(N, '*');
        char currentChar = 'a';
        for(int i = 0; i < N; ++i){
            if(!isalpha(s[i])){
                s[i] = currentChar;
                currentChar += 1;
            }

            if(s[i] > 'z'){
                return "";
            }

            for(int j = 0; j < N; ++j){
                if(lcp[i][j] > 0){
                    s[j] = s[i];
                }
            }
        }

        // Step 2: check if the result s is valid (satisfies all lcp values)
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(!satisfiesLCP(s, i, j, lcp)){
                    return "";
                }
            }
        }

        return s;
    }
};