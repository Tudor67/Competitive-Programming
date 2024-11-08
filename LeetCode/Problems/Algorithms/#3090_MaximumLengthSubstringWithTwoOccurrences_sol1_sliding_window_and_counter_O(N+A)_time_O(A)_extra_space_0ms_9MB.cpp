class Solution {
public:
    int maximumLengthSubstring(string s) {
        const int N = s.length();
        const int A = 26;
        const int FIRST_ELEM = 'a';

        int maxLen = 0;
        vector<int> freq(A);
        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[s[r] - FIRST_ELEM] += 1;
            while(freq[s[r] - FIRST_ELEM] > 2){
                freq[s[l] - FIRST_ELEM] -= 1;
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};