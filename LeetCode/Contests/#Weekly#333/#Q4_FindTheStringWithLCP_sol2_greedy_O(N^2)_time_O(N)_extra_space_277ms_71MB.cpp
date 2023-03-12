class Solution {
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
        for(int i = N - 1; i >= 0; --i){
            for(int j = N - 1; j >= 0; --j){
                int currentLCP = (s[i] == s[j]);
                if(currentLCP == 1 && max(i, j) + 1 < N){
                    currentLCP += lcp[i + 1][j + 1];
                }
                if(currentLCP != lcp[i][j]){
                    return "";
                }
            }
        }

        return s;
    }
};