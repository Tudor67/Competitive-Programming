class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0;
        int b = 0;
        int n = 0;
        int l = 0;
        int o = 0;
        for(char c: text){
            a += (c == 'a');
            b += (c == 'b');
            n += (c == 'n');
            l += (c == 'l');
            o += (c == 'o');
        }
        return min({a, b, n, l / 2, o / 2});
    }
};