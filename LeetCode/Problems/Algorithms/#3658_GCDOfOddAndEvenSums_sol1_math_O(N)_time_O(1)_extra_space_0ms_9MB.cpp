class Solution {
private:
    int gcd(int a, int b){
        while(a > 0 && b > 0){
            if(a > b){
                a %= b;
            }else{
                b %= a;
            }
        }
        return (a + b);
    }
    
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i = 1; i <= n; ++i){
            sumEven += 2 * i;
            sumOdd += 2 * i - 1;
        }
        return gcd(sumEven, sumOdd);
    }
};