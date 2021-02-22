class Solution {
public:
    string intToRoman(int num) {
        static const vector<string> ROMAN_FROM = {"IV", "XL", "CD", "M"};
        
        string answer;
        int curPow = 1000;
        int level = 3;
        while(curPow > 0){
            int q = num / curPow;
            if(q == 0){
                curPow /= 10;
                level -= 1;
            }else if(1 <= q && q <= 3){
                answer += ROMAN_FROM[level][0];
                num -= curPow;
            }else if(q == 4){
                answer += ROMAN_FROM[level];
                num -= 4 * curPow;
            }else if(5 <= q && q <= 8){
                answer += ROMAN_FROM[level][1];
                num -= 5 * curPow;
            }else if(q == 9){
                answer += string({ROMAN_FROM[level][0], ROMAN_FROM[level + 1][0]});
                num -= 9 * curPow;
                curPow /= 10;
                level -= 1;
            }
        }
        
        return answer;
    }
};