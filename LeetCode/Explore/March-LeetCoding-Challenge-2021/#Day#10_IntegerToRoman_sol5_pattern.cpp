class Solution {
private:
    const vector<char> ROMAN_SYMBOLS = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
    string romanSymbols(int digit, int pos){
        vector<pair<int, char>> v;
        if(digit == 0){
            // empty
        }else if(digit <= 3){
            v.emplace_back(digit, ROMAN_SYMBOLS[2 * pos]);
        }else if(digit <= 8){
            v.emplace_back(max(0, 5 - digit), ROMAN_SYMBOLS[2 * pos]);
            v.emplace_back(1, ROMAN_SYMBOLS[2 * pos + 1]);
            v.emplace_back(max(0, digit - 5), ROMAN_SYMBOLS[2 * pos]);
        }else if(digit == 9){
            v.emplace_back(1, ROMAN_SYMBOLS[2 * pos]);
            v.emplace_back(1, ROMAN_SYMBOLS[2 * pos + 2]);
        }
        string s;
        for(const pair<int, char>& P: v){
            s += string(P.first, P.second);
        }
        return s;
    }
    
public:
    string intToRoman(int num) {
        string answer;
        int pos = 0;
        while(num > 0){
            int digit = num % 10;
            answer = romanSymbols(digit, pos) + answer;
            num /= 10;
            pos += 1;
        }
        return answer;
    }
};