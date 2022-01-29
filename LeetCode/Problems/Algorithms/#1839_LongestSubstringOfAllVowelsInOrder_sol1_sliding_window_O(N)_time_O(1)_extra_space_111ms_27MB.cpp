class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const int N = word.length();
        const string VOWELS = "aeiou";
        
        int maxLen = 0;
        int i = 0;
        while(i < N){
            int j = i;
            int vowelIdx = 0;
            while(j < N && vowelIdx < (int)VOWELS.length()){
                if(word[j] == VOWELS[vowelIdx]){
                    while(j < N && word[j] == VOWELS[vowelIdx]){
                        j += 1;
                    }
                    vowelIdx += 1;
                }else{
                    break;
                }
            }
            
            if(vowelIdx == (int)VOWELS.length()){
                maxLen = max(maxLen, j - i);
            }
            
            if(i == j){
                i = j + 1;
            }else{
                i = j;
            }
        }
        
        return maxLen;
    }
};