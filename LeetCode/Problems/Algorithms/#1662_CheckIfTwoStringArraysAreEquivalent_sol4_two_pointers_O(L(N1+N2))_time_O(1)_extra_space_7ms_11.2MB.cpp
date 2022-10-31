class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const int N1 = word1.size();
        const int N2 = word2.size();
        
        int wordIndex1 = 0, index1 = 0;
        int wordIndex2 = 0, index2 = 0;
        
        while(wordIndex1 < N1 && wordIndex2 < N2){
            if(word1[wordIndex1][index1] != word2[wordIndex2][index2]){
                return false;
            }
            
            index1 += 1;
            index2 += 1;
            
            if(index1 == (int)word1[wordIndex1].length()){
                wordIndex1 += 1;
                index1 = 0;
            }
            
            if(index2 == (int)word2[wordIndex2].length()){
                wordIndex2 += 1;
                index2 = 0;
            }
        }
        
        return (wordIndex1 == N1 && wordIndex2 == N2);
    }
};