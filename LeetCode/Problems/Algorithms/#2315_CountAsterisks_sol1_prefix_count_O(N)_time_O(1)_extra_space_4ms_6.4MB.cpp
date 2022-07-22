class Solution {
public:
    int countAsterisks(string s) {
        const int N = s.length();
        
        int res = 0;
        int bars = 0;
        for(char c: s){
            if(c == '|'){
                bars += 1;
            }
            if(bars % 2 == 0){
                if(c == '*'){
                    res += 1;
                }
            }
        }
        
        return res;
    }
};