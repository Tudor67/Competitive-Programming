class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> squares = {0};
        for(int i = 1; i <= c / i; ++i){
            squares.push_back(i * i);
        }
        
        int i = 0;
        int j = (int)squares.size() - 1;
        while(i <= j){
            if(squares[i] < c - squares[j]){
                i += 1;
            }else if(squares[i] > c - squares[j]){
                j -= 1;
            }else{
                return true;
            }
        }
        
        return false;
    }
};