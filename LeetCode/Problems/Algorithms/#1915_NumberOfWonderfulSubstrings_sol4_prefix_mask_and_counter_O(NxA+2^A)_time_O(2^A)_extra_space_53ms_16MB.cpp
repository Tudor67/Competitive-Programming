class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = word.length();
        const int MAX_CHAR = *max_element(word.begin(), word.end());
        const int A = MAX_CHAR - 'a' + 1;

        long long res = 0;
        int prefMask = 0;
        vector<int> freq(1 << A);
        freq[0] = 1;

        for(int i = 0; i < N; ++i){
            prefMask ^= (1 << (word[i] - 'a'));

            res += freq[prefMask];
            for(char c = 'a'; c <= MAX_CHAR; ++c){
                res += freq[prefMask ^ (1 << (c - 'a'))];
            }

            freq[prefMask] += 1;
        }

        return res;
    }
};