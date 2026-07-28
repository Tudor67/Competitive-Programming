class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.begin() + s.length() / 2);
        copy(s.begin(), s.begin() + s.length() / 2, s.rbegin());
        return s;
    }
};