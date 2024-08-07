class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();
        const int A = 26;

        vector<int> f(A);
        for(char c: word){
            f[c - 'a'] += 1;
        }

        sort(f.rbegin(), f.rend());

        int totalCost = 0;
        for(int i = 0; i < A && f[i] >= 1; ++i){
            int pushesPerChar = 1 + (i / 8);
            int charFreq = f[i];
            int charCost = pushesPerChar * charFreq;
            totalCost += charCost;
        }

        return totalCost;
    }
};