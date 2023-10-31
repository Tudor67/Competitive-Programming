class Solution {
private:
    bool canBePartitioned(int num, int p10, int x, int sum, int target){
        if(x + sum > target){
            return false;
        }
        if(num == 0){
            return (x + sum == target);
        }
        return canBePartitioned(num / 10, p10 * 10, (num % 10) * p10 + x, sum, target) ||
               canBePartitioned(num / 10, 1, 0, sum + (num % 10) * p10 + x, target);
    }
    
public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            if(canBePartitioned(i * i, 1, 0, 0, i)){
                res += (i * i);
            }
        }
        return res;
    }
};