class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        
        int i1 = 0;
        int i2 = 0;
        int j = 0;
        string s(N1 + N2, '.');
        while(i1 < N1 || i2 < N2){
            if(i1 < N1){
                s[j] = word1[i1];
                j += 1;
                i1 += 1;
            }
            if(i2 < N2){
                s[j] = word2[i2];
                j += 1;
                i2 += 1;
            }
        }
        
        return s;
    }
};