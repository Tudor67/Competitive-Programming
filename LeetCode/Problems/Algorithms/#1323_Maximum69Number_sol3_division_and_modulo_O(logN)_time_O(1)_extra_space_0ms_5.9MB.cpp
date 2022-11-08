class Solution {
public:
    int maximum69Number(int num) {
        int maxPow = 1;
        while(maxPow <= num / 10){
            maxPow *= 10;
        }
        
        while(maxPow > 0){
            if((num / maxPow) % 10 == 6){
                return (num / maxPow + 3) * maxPow + (num % maxPow);
            }
            maxPow /= 10;
        }
        
        return num;
    }
};