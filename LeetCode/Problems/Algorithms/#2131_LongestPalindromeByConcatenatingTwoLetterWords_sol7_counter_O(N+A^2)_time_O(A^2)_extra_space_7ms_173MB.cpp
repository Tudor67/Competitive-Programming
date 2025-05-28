class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();
        const int A = 26;

        int maxLen = 0;

        vector<vector<int>> freq(A, vector<int>(A));
        for(string& word: words){
            int a = word[0] - 'a';
            int b = word[1] - 'a';
            if(freq[b][a] >= 1){
                freq[b][a] -= 1;
                maxLen += 4;
            }else{
                freq[a][b] += 1;
            }
        }

        for(char c = 'a'; c <= 'z'; ++c){
            if(freq[c - 'a'][c - 'a'] >= 1){
                maxLen += 2;
                break;
            }
        }

        return maxLen;
    }
};