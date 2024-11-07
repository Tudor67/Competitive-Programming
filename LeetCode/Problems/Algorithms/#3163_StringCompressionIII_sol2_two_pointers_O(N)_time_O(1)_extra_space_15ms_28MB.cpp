class Solution {
public:
    string compressedString(string word) {
        const int N = word.length();

        string compressedWord;

        int i = 0;
        while(i < N){
            int len = 1;
            while(i + len < N && len < 9 && word[i] == word[i + len]){
                len += 1;
            }

            compressedWord += char('0' + len);
            compressedWord += word[i];

            i += len;
        }
        
        return compressedWord;
    }
};