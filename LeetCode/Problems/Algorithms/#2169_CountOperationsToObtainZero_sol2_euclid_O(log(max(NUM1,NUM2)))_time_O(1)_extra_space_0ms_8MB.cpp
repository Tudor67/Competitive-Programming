class Solution {
public:
    int countOperations(int num1, int num2) {
        int totalOps = 0;
        while(num1 > 0 && num2 > 0){
            if(num1 > num2){
                totalOps += num1 / num2;
                num1 %= num2;
            }else{
                totalOps += num2 / num1;
                num2 %= num1;
            }
        }
        return totalOps;
    }
};