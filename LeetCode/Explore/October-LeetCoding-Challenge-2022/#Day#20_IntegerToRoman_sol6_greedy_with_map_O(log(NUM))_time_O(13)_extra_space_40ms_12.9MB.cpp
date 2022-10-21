class Solution {
public:
    string intToRoman(int num) {
        const map<int, string> INT_TO_ROMAN = {
            {1, "I"},
            {4, "IV"}, {5, "V"},
            {9, "IX"}, {10, "X"},
            {40, "XL"}, {50, "L"},
            {90, "XC"}, {100, "C"},
            {400, "CD"}, {500, "D"},
            {900, "CM"}, {1000, "M"}
        };
        
        string s;
        map<int, string>::const_reverse_iterator it = INT_TO_ROMAN.rbegin();
        while(num > 0){
            if(it->first <= num){
                num -= it->first;
                s += it->second;
            }else{
                it = next(it);
            }
        }
        
        return s;
    }
};