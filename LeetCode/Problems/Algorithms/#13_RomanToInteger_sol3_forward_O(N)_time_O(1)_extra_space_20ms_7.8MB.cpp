class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> ROMAN_TO_INT = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        const int N = s.length();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            res += ROMAN_TO_INT.at(s[i]);
            if(i > 0 && ROMAN_TO_INT.at(s[i - 1]) < ROMAN_TO_INT.at(s[i])){
                res -= 2 * ROMAN_TO_INT.at(s[i - 1]);
            }
        }
        
        return res;
    }
};