class Solution {
private:
    bool canBePartitioned(string& numStr, int targetSum, int val, int index){
        if(index == (int)numStr.length()){
            return (val == targetSum);
        }
        return canBePartitioned(numStr, targetSum, val * 10 + numStr[index] - '0', index + 1)
               ||
               canBePartitioned(numStr, targetSum - (val * 10 + numStr[index] - '0'), 0, index + 1);
    }

public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            string numStr = to_string(i * i);
            int targetSum = i;
            if(canBePartitioned(numStr, targetSum, 0, 0)){
                res += i * i;
            }
        }
        return res;
    }
};