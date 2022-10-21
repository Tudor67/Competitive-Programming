class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> INT_ROMAN_SORTED_PAIRS = {
            {1, "I"},
            {4, "IV"}, {5, "V"},
            {9, "IX"}, {10, "X"},
            {40, "XL"}, {50, "L"},
            {90, "XC"}, {100, "C"},
            {400, "CD"}, {500, "D"},
            {900, "CM"}, {1000, "M"}
        };
        
        string s;
        int idx = (int)INT_ROMAN_SORTED_PAIRS.size() - 1;
        while(num > 0){
            if(INT_ROMAN_SORTED_PAIRS[idx].first <= num){
                num -= INT_ROMAN_SORTED_PAIRS[idx].first;
                s += INT_ROMAN_SORTED_PAIRS[idx].second;
            }else{
                idx -= 1;
            }
        }
        
        return s;
    }
};