class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y){
            return (X - Y);
        }
        if(Y % 2 == 0){
            return 1 + brokenCalc(X, Y / 2);
        }
        return 1 + brokenCalc(X, Y + 1);
    }
};