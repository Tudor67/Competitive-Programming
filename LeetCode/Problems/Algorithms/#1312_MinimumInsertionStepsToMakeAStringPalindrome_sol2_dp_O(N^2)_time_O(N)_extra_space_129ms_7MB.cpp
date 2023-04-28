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

        // At ith iteration:
        //    lcs[i % 2][j]: length of the longest common subsequence of s[0 .. i] and sRev[0 .. j]
        vector<vector<int>> lcs(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(s[i] == sRev[j]){
                    lcs[i % 2][j] = 1 + getVal(lcs, (i - 1) % 2, j - 1);
                }else{
                    lcs[i % 2][j] = max(getVal(lcs, (i - 1) % 2, j), getVal(lcs, i % 2, j - 1));
                }
            }
        }

        return N - lcs[(N - 1) % 2][N - 1];
    }
};