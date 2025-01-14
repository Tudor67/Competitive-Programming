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
            if(charFreq >= 1){
                if(charFreq % 2 == 0){
                    minLen += 2;
                }else{
                    minLen += 1;
                }
            }
        }

        return minLen;
    }
};