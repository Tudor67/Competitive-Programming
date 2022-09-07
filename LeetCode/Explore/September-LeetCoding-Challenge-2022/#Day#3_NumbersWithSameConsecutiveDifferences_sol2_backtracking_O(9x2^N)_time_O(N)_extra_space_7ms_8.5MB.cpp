class Solution {
private:
    void back(int level, int num, int n, int k, vector<int>& res){
        if(level == n){
            res.push_back(num);
        }else{
            int lastDigit = num % 10;
            if(lastDigit - k >= 0){
                back(level + 1, num * 10 + (lastDigit - k), n, k, res);
            }
            if(lastDigit + k <= 9 && k >= 1){
                back(level + 1, num * 10 + (lastDigit + k), n, k, res);
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int firstDigit = 1; firstDigit <= 9; ++firstDigit){
            back(1, firstDigit, n, k, res);
        }
        return res;
    }
};