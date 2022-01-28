class Solution {
public:
    bool detectCapitalUse(string word) {
        static regex r1("[A-Z]+");
        static regex r2("[a-z]+");
        static regex r3("[A-Z][a-z]*");
        return regex_match(word, r1) || regex_match(word, r2) || regex_match(word, r3);
    }
};