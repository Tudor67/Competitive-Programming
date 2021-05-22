class Solution {
public:
    bool isNumber(string s) {
        static regex r("[+-]?(\\d+(\\.\\d*)?|(\\.\\d+))([eE][+-]?\\d+)?");
        return regex_match(s, r);
    }
};