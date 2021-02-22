class Solution {
public:
    int brokenCalc(int X, int Y) {
        int steps = 0;
        while(X < Y){
            if(Y % 2 == 0){
                Y /= 2;
            }else{
                Y += 1;
            }
            steps += 1;
        }
        steps += (X - Y);
        return steps;
    }
};