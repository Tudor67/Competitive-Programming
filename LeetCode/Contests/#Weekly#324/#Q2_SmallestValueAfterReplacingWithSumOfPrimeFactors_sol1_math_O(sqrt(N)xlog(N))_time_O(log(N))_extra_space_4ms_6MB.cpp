class Solution {
private:
    void collectPrimeFactors(int num, vector<int>& factors){
        factors.clear();
        for(int i = 2; i * i <= num; ++i){
            while(num % i == 0){
                num /= i;
                factors.push_back(i);
            }
        }
        if(num > 1){
            factors.push_back(num);
        }
    }
    
public:
    int smallestValue(int n) {
        vector<int> factors;
        int prevNum = -1;
        int currentNum = n;
        while(prevNum != currentNum){
            prevNum = currentNum;
            collectPrimeFactors(currentNum, factors);
            currentNum = accumulate(factors.begin(), factors.end(), 0);
        }
        return currentNum;
    }
};