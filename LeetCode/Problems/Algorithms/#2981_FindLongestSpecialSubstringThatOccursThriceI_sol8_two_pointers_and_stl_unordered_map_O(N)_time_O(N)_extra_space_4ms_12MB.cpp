class Solution {
private:
    struct PairHash {
        size_t operator()(const pair<char, int>& P) const {
            size_t a = P.first;
            size_t b = P.second;
            return a | (b << 10);
        }
    };

public:
    int maximumLength(string s) {
        const int N = s.length();

        unordered_map<pair<char, int>, int, PairHash> freq;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && s[l] == s[r]){
                r += 1;
            }
            int len = r - l;
            freq[{s[l], len}] += 1;
            freq[{s[l], len - 1}] += 2;
            freq[{s[l], len - 2}] += 3;
            l = r;
        }

        int maxLen = -1;
        for(const pair<const pair<char, int>, int>& P: freq){
            char c = P.first.first;
            int len = P.first.second;
            int lenFreq = P.second;
            if(len >= 1 && lenFreq >= 3){
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};