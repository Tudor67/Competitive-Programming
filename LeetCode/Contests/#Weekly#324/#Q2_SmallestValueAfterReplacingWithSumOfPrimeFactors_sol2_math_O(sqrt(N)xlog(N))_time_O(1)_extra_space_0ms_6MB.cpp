class Solution {
private:
    int computeSumOfPrimeFactors(int num){
        int sum = 0;
        for(int i = 2; i * i <= num; ++i){
            while(num % i == 0){
                num /= i;
                sum += i;
            }
        }
        if(num > 1){
            sum += num;
        }
        return sum;
    }
    
public:
    int smallestValue(int n) {
        int prevNum = -1;
        int currentNum = n;
        while(prevNum != currentNum){
            prevNum = currentNum;
            currentNum = computeSumOfPrimeFactors(currentNum);
        }
        return currentNum;
    }
};