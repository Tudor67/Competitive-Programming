class Solution {
public:
    bool isNumber(string s) {
        static regex r(R"_([+-]?(\d+(\.\d*)?|(\.\d+))([eE][+-]?\d+)?)_");
        return regex_match(s, r);
    }
};