class Solution {
private:
    const map<int, string, greater<int>> roman = {
        {1, "I"},
        {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
        {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
    };
    
public:
    string intToRoman(int num) {
        string answer;
        for(const pair<int, string>& p: roman){
            while(num >= p.first){
                num -= p.first;
                answer += p.second;
            }
        }
        
        return answer;
    }
};