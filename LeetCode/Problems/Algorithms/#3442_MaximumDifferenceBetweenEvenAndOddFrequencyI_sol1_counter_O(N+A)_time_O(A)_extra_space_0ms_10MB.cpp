class Solution {
public:
    int maxDifference(string s) {
        const int N = s.length();
        const int A = 26;
        const char FIRST_CHAR = 'a';

        vector<int> freqOf(A);
        for(char c: s){
            freqOf[c - FIRST_CHAR] += 1;
        }

        int maxOddFreq = 0;
        int minEvenFreq = N;
        for(int freq: freqOf){
            if(freq > 0){
                if(freq % 2 == 0){
                    minEvenFreq = min(minEvenFreq, freq);
                }else{
                    maxOddFreq = max(maxOddFreq, freq);
                }
            }
        }

        return maxOddFreq - minEvenFreq;
    }
};