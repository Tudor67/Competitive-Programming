class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return *max_element(s.begin(), s.end()) ==
               *max_element(target.begin(), target.end());
    }
};