class Solution {
public:
    bool canConstruct(string s, int k) {
        const int N = s.length();
        const int A = 26;

        vector<int> freqParity(A);
        for(char c: s){
            freqParity[c - 'a'] += 1;
            freqParity[c - 'a'] %= 2;
        }

        int minPalindromes = count(freqParity.begin(), freqParity.end(), 1);
        int maxPalindromes = N;

        return (minPalindromes <= k && k <= maxPalindromes);
    }
};