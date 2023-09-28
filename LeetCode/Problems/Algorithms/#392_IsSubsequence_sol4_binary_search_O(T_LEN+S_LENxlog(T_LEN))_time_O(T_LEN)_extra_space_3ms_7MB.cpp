class Solution {
private:
    const int A = 26;
    const char FIRST_CHAR = 'a';

    void computeIndicesOfChars(string& t, vector<vector<int>>& indicesOf){
        const int T_LEN = t.length();
        for(int i = 0; i < T_LEN; ++i){
            indicesOf[t[i] - FIRST_CHAR].push_back(i);
        }
    }

public:
    bool isSubsequence(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();

        vector<vector<int>> charToIndices(A);
        computeIndicesOfChars(t, charToIndices);

        int tIndex = 0;
        for(char c: s){
            vector<int>& indices = charToIndices[c - FIRST_CHAR];
            vector<int>::iterator it = lower_bound(indices.begin(), indices.end(), tIndex);
            if(it == indices.end()){
                return false;
            }else{
                tIndex = *it + 1;
            }
        }

        return true;
    }
};