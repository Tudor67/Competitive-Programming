class Solution {
public:
    char findTheDifference(string s, string t) {
        int sSum = accumulate(s.begin(), s.end(), 0);
        int tSum = accumulate(t.begin(), t.end(), 0);
        return char(tSum - sSum);
    }
};