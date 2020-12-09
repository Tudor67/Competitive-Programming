class Solution {
public:
    int integerReplacement(int inputN) {
        unsigned int n = inputN;
        int steps = 0;
        while(n != 1){
            steps += 1;
            if(n % 2 == 0){
                n /= 2;
            }else{
                if(((n - 1) / 2) % 2 == 0 || n == 3){
                    n -= 1;
                }else{
                    n += 1;
                }
            }
        }
        return steps;
    }
};