class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> squaresSet;
        for(unsigned int a = 0; a * a <= c; ++a){
            squaresSet.insert(a * a);
        }

        for(unsigned int b = 0; b * b <= c; ++b){
            if(squaresSet.count(c - b * b)){
                return true;
            }
        }

        return false;
    }
};