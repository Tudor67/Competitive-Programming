class Solution {
public:
    int maximumLengthSubstring(string s) {
        const int N = s.length();
        const int A = 26;

        int maxLen = 0;
        vector<int> freq(A);

        for(int l = 0, r = 0; r < N; ++r){
            ++freq[s[r] - 'a'];
            while(freq[s[r] - 'a'] > 2){
                --freq[s[l] - 'a'];
                ++l;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};