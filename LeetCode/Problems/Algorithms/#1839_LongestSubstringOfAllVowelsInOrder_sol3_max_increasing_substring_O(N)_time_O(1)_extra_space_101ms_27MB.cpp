class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const int N = word.length();
        
        int maxLen = 0;
        int len = 1;
        int uniqueVowels = 1;
        for(int i = 1; i < N; ++i){
            if(word[i - 1] == word[i]){
                ++len;
            }else if(word[i - 1] < word[i]){
                ++len;
                ++uniqueVowels;
            }else{
                len = 1;
                uniqueVowels = 1;
            }
            
            if(uniqueVowels == 5){
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};