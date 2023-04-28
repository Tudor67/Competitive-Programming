class Solution {
private:
    int getVal(vector<vector<int>>& lcs, int i, int j){
        if(0 <= i && i < (int)lcs.size() && 0 <= j && j < (int)lcs[i].size()){
            return lcs[i][j];
        }
        return 0;
    }

public:
    int minInsertions(string s) {
        const int N = s.length();

        string sRev(s.rbegin(), s.rend());

        // lcs[i][j]: length of the longest common subsequence of s[0 .. i] and sRev[0 .. j]
        vector<vector<int>> lcs(N, vector<int>(N));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(s[i] == sRev[j]){
                    lcs[i][j] = 1 + getVal(lcs, i - 1, j - 1);
                }else{
                    lcs[i][j] = max(getVal(lcs, i - 1, j), getVal(lcs, i, j - 1));
                }
            }
        }

        return N - lcs[N - 1][N - 1];
    }
};