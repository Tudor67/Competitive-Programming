class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
        while(startValue < target){
            if(target % 2 == 0){
                target /= 2;
            }else{
                target += 1;
            }
            operations += 1;
        }
        operations += (startValue - target);
        return operations;
    }
};