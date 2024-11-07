class Solution {
public:
    string compressedString(string word) {
        const int N = word.length();

        string compressedWord;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && word[l] == word[r]){
                r += 1;
            }

            int len = r - l;
            while(len >= 1){
                int k = min(9, len);
                compressedWord += char('0' + k);
                compressedWord += word[l];
                len -= k;
            }

            l = r;
        }
        
        return compressedWord;
    }
};