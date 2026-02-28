class Solution {
private:
    bool sameMinMaxFreq(vector<int>& freqOf){
        int minFreq = INT_MAX;
        int maxFreq = 0;
        for(int freq: freqOf){
            if(freq > 0){
                minFreq = min(minFreq, freq);
                maxFreq = max(maxFreq, freq);
            }
        }
        return (minFreq == maxFreq);
    }

public:
    int longestBalanced(string s) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        const char FIRST_ELEM = 'a';

        int maxLen = 0;
        vector<int> freqOf(ALPHABET_SIZE);

        for(int i = 0; i < N; ++i){
            fill(freqOf.begin(), freqOf.end(), 0);
            for(int j = i; j < N; ++j){
                freqOf[s[j] - FIRST_ELEM] += 1;
                if(sameMinMaxFreq(freqOf)){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};