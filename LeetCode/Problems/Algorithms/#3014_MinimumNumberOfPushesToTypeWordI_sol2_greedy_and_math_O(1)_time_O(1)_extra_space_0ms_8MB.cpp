class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();

        int fullBlocks = N / 8;
        int rem = N % 8;

        return 8 * fullBlocks * (fullBlocks + 1) / 2 + (fullBlocks + 1) * rem;
    }
};