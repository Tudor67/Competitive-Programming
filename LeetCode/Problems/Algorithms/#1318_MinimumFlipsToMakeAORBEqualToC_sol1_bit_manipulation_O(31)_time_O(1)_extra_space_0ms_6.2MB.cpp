class Solution {
public:
    int minFlips(int a, int b, int c) {
        const int MAX_BIT = 30;
        int flips = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int current = ((a | b) >> bit) & 1;
            int expected = (c >> bit) & 1;
            if(current == 0 && expected == 1){
                flips += 1;
            }else if(current == 1 && expected == 0){
                flips += ((a >> bit) & 1);
                flips += ((b >> bit) & 1);
            }
        }
        return flips;
    }
};