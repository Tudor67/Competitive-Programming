class Solution {
public:
    int maximum69Number (int num) {
        int bestPow = 0;
        for(int p = 1; p <= num; p *= 10){
            if((num / p) % 10 == 6){
                bestPow = p;
            }
        }
        return num - 6 * bestPow + 9 * bestPow;
    }
};