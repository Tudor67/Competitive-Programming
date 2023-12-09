class Solution {
public:
    string largestOddNumber(string num) {
        return num.substr(0, num.find_last_of("13579") + 1);
    }
};