class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const int N1 = word1.size();
        const int N2 = word2.size();

        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;
        while(i1 < N1 && i2 < N2){
            if(word1[i1][j1] == word2[i2][j2]){
                j1 += 1;
                j2 += 1;
            }else{
                return false;
            }

            if(j1 == (int)word1[i1].length()){
                i1 += 1;
                j1 = 0;
            }
            if(j2 == (int)word2[i2].length()){
                i2 += 1;
                j2 = 0;
            }
        }

        return (i1 == N1 && i2 == N2);
    }
};