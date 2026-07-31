class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: word){
            freq[c - 'a'] += 1;
        }

        sort(freq.rbegin(), freq.rend());

        int totalCost = 0;
        for(int i = 0; i < A; ++i){
            totalCost += freq[i] * (1 + i / 8);
        }

        return totalCost;
    }
};