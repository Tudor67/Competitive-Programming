class Solution {
public:
    string largestMerge(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        
        int i1 = 0;
        int i2 = 0;
        string merged;
        while(i1 < N1 || i2 < N2){
            if(word1.compare(i1, string::npos, word2, i2) >= 0){
                merged += word1[i1];
                i1 += 1;
            }else{
                merged += word2[i2];
                i2 += 1;
            }
        }
        
        return merged;
    }
};