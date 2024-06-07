class Solution {
public:
    int longestPalindrome(string s) {
        const int N = s.length();

        unsigned long long freqParityMask = 0;
        for(char c: s){
            freqParityMask ^= (1ULL << (c - 'A'));
        }

        int oddFreqs = popcount(freqParityMask);

        return N - max(0, oddFreqs - 1);
    }
};