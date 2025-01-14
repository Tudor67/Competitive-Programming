class Solution {
public:
    int minimumLength(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freqOf(A);
        for(char c: s){
            freqOf[c - 'a'] += 1;
        }

        int minLen = 0;
        for(int charFreq: freqOf){
            while(charFreq >= 3){
                charFreq -= 2;
            }
            minLen += charFreq;
        }

        return minLen;
    }
};