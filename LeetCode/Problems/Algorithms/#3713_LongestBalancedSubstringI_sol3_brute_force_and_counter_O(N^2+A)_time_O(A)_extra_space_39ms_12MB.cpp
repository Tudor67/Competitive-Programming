class Solution {
public:
    int longestBalanced(string s) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        const char FIRST_ELEM = 'a';

        int maxLen = 0;
        vector<int> freqOf(ALPHABET_SIZE);

        for(int i = 0; i < N; ++i){
            int distinctChars = 0;
            int maxFreq = 0;
            fill(freqOf.begin(), freqOf.end(), 0);
            
            for(int j = i; j < N; ++j){
                int charID = s[j] - FIRST_ELEM;
                
                freqOf[charID] += 1;

                if(freqOf[charID] == 1){
                    distinctChars += 1;
                }
                maxFreq = max(maxFreq, freqOf[charID]);

                if(distinctChars * maxFreq == j - i + 1){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};