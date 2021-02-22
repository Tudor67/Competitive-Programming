class Solution {
public:
    string intToRoman(int num) {
        static const vector<pair<int, string>> ROMANS = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                                         {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                                         {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
                                                         {1000, "M"}};
        
        string answer;
        for(int i = (int)ROMANS.size() - 1; i >= 0; --i){
            while(num >= ROMANS[i].first){
                num -= ROMANS[i].first;
                answer += ROMANS[i].second;
            }
        }
        
        return answer;
    }
};