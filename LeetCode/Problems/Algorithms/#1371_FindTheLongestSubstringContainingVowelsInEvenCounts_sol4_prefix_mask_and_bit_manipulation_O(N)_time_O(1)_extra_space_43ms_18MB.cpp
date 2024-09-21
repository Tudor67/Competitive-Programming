class Solution {
public:
    int findTheLongestSubstring(string s) {
        const int N = s.length();
        const int A = 26;
        const int FULL_MASK = (1 << 5) - 1;

        vector<int> charID(A);
        charID['a' - 'a'] = 1;
        charID['e' - 'a'] = 2;
        charID['i' - 'a'] = 4;
        charID['o' - 'a'] = 8;
        charID['u' - 'a'] = 16;

        int maxLen = 0;
        int prefMask = 0;
        vector<int> firstPos(FULL_MASK + 1, N);
        firstPos[0] = -1;

        for(int i = 0; i < N; ++i){
            prefMask ^= charID[s[i] - 'a'];
            maxLen = max(maxLen, i - firstPos[prefMask]);
            firstPos[prefMask] = min(firstPos[prefMask], i);
        }

        return maxLen;
    }
};