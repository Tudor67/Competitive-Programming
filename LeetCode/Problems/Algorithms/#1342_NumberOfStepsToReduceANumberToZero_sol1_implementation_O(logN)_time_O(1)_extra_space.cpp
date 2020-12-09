class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while(num > 0){
            if(num & 1){
                num -= 1;
                steps += 1;
            }
            if(num > 0){
                num /= 2;
                steps += 1;
            }
        }
        return steps;
    }
};