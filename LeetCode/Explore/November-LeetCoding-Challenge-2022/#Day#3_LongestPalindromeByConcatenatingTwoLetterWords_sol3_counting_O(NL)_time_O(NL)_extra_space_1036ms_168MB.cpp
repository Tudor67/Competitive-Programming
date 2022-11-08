class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();
        
        unordered_map<string, int> count;
        for(string& word: words){
            count[word] += 1;
        }
        
        int totalLen = 0;
        int extraLen = 0;
        for(string& word: words){
            string revWord(word.rbegin(), word.rend());
            int wordLen = word.length();
            if(word == revWord){
                if(count[word] >= 2){
                    count[word] -= 2;
                    totalLen += 2 * wordLen;
                }else if(count[word] == 1){
                    count[word] -= 1;
                    extraLen = max(extraLen, wordLen);
                }
            }else{
                if(count[word] >= 1 && count[revWord] >= 1){
                    count[word] -= 1;
                    count[revWord] -= 1;
                    totalLen += 2 * wordLen;
                }
            }
        }
        
        return totalLen + extraLen;
    }
};