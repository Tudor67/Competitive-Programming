class Solution {
public:
    bool canConstruct(string s, int k) {
        const int N = s.length();

        int freqParityMask = 0;
        for(char c: s){
            freqParityMask ^= (1 << (c - 'a'));
        }

        int minPalindromes = __builtin_popcount(freqParityMask);
        int maxPalindromes = N;

        return (minPalindromes <= k && k <= maxPalindromes);
    }
};