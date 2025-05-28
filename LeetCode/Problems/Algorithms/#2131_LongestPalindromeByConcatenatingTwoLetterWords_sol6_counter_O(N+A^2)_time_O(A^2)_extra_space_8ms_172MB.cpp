class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();
        const int A = 26;

        int maxLen = 0;

        vector<int> freq(A * A);
        for(string& word: words){
            int code = (word[0] - 'a') * A + (word[1] - 'a');
            int complCode = (word[1] - 'a') * A + (word[0] - 'a');
            if(freq[complCode] >= 1){
                freq[complCode] -= 1;
                maxLen += 4;
            }else{
                freq[code] += 1;
            }
        }

        for(char c = 'a'; c <= 'z'; ++c){
            int code = (c - 'a') * A + (c - 'a');
            if(freq[code] >= 1){
                maxLen += 2;
                break;
            }
        }

        return maxLen;
    }
};