class Solution {
public:
    string removeTrailingZeros(string num) {
        while((int)num.length() >= 2 && num.back() == '0'){
            num.pop_back();
        }
        return num;
    }
};