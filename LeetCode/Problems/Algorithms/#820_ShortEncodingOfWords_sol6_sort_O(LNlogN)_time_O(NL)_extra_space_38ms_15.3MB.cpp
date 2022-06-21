class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        const int N = words.size();
        
        vector<string> sortedWords = words;
        for(int i = 0; i < N; ++i){
            reverse(sortedWords[i].begin(), sortedWords[i].end());
        }
        
        sort(sortedWords.begin(), sortedWords.end());
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            int len = sortedWords[i].length();
            if(i == N - 1 || sortedWords[i].compare(0, len, sortedWords[i + 1], 0, len) != 0){
                res += len;
                res += 1;
            }
        }
        
        return res;
    }
};