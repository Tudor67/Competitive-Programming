class Solution {
private:
    int f(int x, int y){
        if(x <= y){
            return (y - x);
        }

        int minOps = x - y;
        minOps = min(minOps, 1 + (x % 5) + f(x / 5, y));
        minOps = min(minOps, 1 + (5 - (x % 5)) + f(1 + x / 5, y));
        minOps = min(minOps, 1 + (x % 11) + f(x / 11, y));
        minOps = min(minOps, 1 + (11 - (x % 11)) + f(1 + x / 11, y));

        return minOps;
    }

public:
    int minimumOperationsToMakeEqual(int x, int y) {
        return f(x, y);
    }
};