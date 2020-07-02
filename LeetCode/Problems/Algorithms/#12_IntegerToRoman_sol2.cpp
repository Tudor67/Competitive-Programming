class Solution {
private:
    const vector<pair<int, string>> int_roman = {
        {1, "I"},
        {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
        {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
    };
    
public:
    string intToRoman(int num) {
        string answer;
        for(int i = (int)int_roman.size() - 1; i >= 0; --i){
            pair<int, string> p = int_roman[i];
            while(num >= p.first){
                num -= p.first;
                answer += p.second;
            }
        }
        
        return answer;
    }
};