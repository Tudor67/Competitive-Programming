class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();

        string res;
        res.reserve(N1 + N2);
        
        for(int i = 0; i < max(N1, N2); ++i){
            if(i < N1){
                res.push_back(word1[i]);
            }
            if(i < N2){
                res.push_back(word2[i]);
            }
        }

        return res;
    }
};