class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> ROMAN_TO_INT = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        const int N = s.length();
        
        int res = 0;
        for(int i = N - 1; i >= 0; --i){
            if(i + 1 < N && ROMAN_TO_INT.at(s[i]) < ROMAN_TO_INT.at(s[i + 1])){
                res -= ROMAN_TO_INT.at(s[i]);
            }else{
                res += ROMAN_TO_INT.at(s[i]);
            }
        }
        
        return res;
    }
};