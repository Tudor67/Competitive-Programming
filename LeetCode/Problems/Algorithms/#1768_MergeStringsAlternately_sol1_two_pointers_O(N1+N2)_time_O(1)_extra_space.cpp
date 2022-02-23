class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        
        string s(N1 + N2, '.');
        int j = 0;
        for(int i = 0; i < max(N1, N2); ++i){
            if(i < N1){
                s[j] = word1[i];
                ++j;
            }
            if(i < N2){
                s[j] = word2[i];
                ++j;
            }
        }
        
        return s;
    }
};