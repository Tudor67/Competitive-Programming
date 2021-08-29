class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> squares;
        for(int b = 0; b == 0 || b <= c / b; ++b){
            int bSquared = b * b;
            int complement = c - b * b;
            squares.push_back(bSquared);
            bool complementFound = binary_search(squares.begin(), squares.end(), complement);
            if(complementFound){
                return true;
            }
        }
        return false;
    }
};