class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0;
        int b = 0;
        int n = 0;
        int l = 0;
        int o = 0;
        for(char c: text){
            if(c == 'a'){
                a += 1;
            }else if(c == 'b'){
                b += 1;
            }else if(c == 'n'){
                n += 1;
            }else if(c == 'l'){
                l += 1;
            }else if(c == 'o'){
                o += 1;
            }
        }
        return min({a, b, n, l / 2, o / 2});
    }
};