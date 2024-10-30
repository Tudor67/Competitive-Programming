class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cFreq = count(s.begin(), s.end(), c);
        return cFreq * (cFreq + 1) / 2;
    }
};