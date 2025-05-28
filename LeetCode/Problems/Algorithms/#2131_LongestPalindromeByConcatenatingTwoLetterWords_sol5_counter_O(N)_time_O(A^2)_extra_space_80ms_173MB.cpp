class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();

        int maxLen = 0;

        unordered_map<string, int> freq;
        for(string& word: words){
            string revWord(word.rbegin(), word.rend());
            if(freq[revWord] >= 1){
                freq[revWord] -= 1;
                maxLen += 4;
            }else{
                freq[word] += 1;
            }
        }

        for(auto& [word, wordFreq]: freq){
            if(wordFreq >= 1 && word[0] == word[1]){
                maxLen += 2;
                break;
            }
        }

        return maxLen;
    }
};