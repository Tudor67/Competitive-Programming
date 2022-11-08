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
        for(const pair<string, int>& P: count){
            string word = P.first;
            string revWord(word.rbegin(), word.rend());
            int wordLen = word.length();
            if(word == revWord){
                int pairs = count[word] / 2;
                totalLen += pairs * 2 * wordLen;
                if(count[word] % 2 == 1){
                    extraLen = max(extraLen, wordLen);
                }
                count[word] = 0;
            }else if(count.count(revWord)){
                int pairs = min(count[word], count[revWord]);
                totalLen += pairs * 2 * wordLen;
                count[word] = 0;
                count[revWord] = 0;
            }
        }
        
        return totalLen + extraLen;
    }
};