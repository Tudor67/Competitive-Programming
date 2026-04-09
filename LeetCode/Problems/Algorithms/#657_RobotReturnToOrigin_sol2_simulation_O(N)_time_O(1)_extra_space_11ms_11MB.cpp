class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(char c: moves){
            if(c == 'L'){
                --x;
            }else if(c == 'R'){
                ++x;
            }else if(c == 'D'){
                --y;
            }else if(c == 'U'){
                ++y;
            }
        }
        return (x == 0 && y == 0);
    }
};