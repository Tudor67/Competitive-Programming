class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> sMultiset(s.begin(), s.end());
        multiset<char> tMultiset(t.begin(), t.end());
        return (sMultiset == tMultiset);
    }
};