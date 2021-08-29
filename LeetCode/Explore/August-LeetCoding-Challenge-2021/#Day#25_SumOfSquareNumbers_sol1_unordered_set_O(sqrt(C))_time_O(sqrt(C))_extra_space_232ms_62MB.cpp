class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> squares;
        for(int b = 0; b == 0 || b <= c / b; ++b){
            int bSquared = b * b;
            int complement = c - b * b;
            squares.insert(bSquared);
            if(squares.count(complement)){
                return true;
            }
        }
        return false;
    }
};