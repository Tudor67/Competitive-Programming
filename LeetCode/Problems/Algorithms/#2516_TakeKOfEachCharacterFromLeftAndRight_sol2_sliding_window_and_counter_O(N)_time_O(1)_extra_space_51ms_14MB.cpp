class Solution {
public:
    int takeCharacters(string s, int k) {
        const int N = s.length();

        unordered_map<char, int> totalFreq;
        for(char c: s){
            totalFreq[c] += 1;
        }

        if(min({totalFreq['a'], totalFreq['b'], totalFreq['c']}) < k){
            return -1;
        }

        int maxLen = 0;
        int l = 0;
        unordered_map<char, int> wFreq;
        for(int r = 0; r < N; ++r){
            wFreq[s[r]] += 1;
            while(totalFreq[s[r]] - wFreq[s[r]] < k){
                wFreq[s[l]] -= 1;
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return N - maxLen;
    }
};