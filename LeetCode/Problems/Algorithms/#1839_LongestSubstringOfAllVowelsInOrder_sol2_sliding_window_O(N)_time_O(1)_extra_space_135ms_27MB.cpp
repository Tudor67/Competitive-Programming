class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const int N = word.length();
        
        int maxLen = 0;
        int i = 0;
        while(i < N){
            if(word[i] == 'a'){
                int j = i + 1;
                int changes = 0;
                while(j < N && word[j - 1] <= word[j]){
                    changes += (int)(word[j - 1] < word[j]);
                    j += 1;
                }
                if(changes == 4){
                    maxLen = max(maxLen, j - i);
                }
                i = j;
            }else{
                i += 1;
            }
        }
        
        return maxLen;
    }
};