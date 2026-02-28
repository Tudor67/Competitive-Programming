class Solution {
public:
    int longestBalanced(string s) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        const char FIRST_ELEM = 'a';

        int maxLen = 0;
        vector<int> freqOf(ALPHABET_SIZE);
        vector<int> ff(N + 1);

        for(int i = 0; i < N; ++i){
            int distinctChars = 0;

            ff[0] = 0;
            for(int charID = 0; charID < ALPHABET_SIZE; ++charID){
                ff[freqOf[charID]] = 0;
                freqOf[charID] = 0;
            }

            for(int j = i; j < N; ++j){
                int charID = s[j] - FIRST_ELEM;
                
                ff[freqOf[charID]] -= 1;
                freqOf[charID] += 1;
                ff[freqOf[charID]] += 1;

                if(freqOf[charID] == 1){
                    distinctChars += 1;
                }

                if(ff[freqOf[charID]] == distinctChars){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};