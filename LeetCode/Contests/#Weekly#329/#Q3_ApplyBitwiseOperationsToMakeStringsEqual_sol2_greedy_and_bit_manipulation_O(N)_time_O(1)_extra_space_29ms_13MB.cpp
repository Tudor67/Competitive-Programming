class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int sOnes = count(s.begin(), s.end(), '1');
        int tOnes = count(target.begin(), target.end(), '1');
        return (sOnes == 0 && tOnes == 0) || (sOnes >= 1 && tOnes >= 1);
    }
};