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
        int sumEven = n * (n + 1);
        int sumOdd = n * n;
        return gcd(sumEven, sumOdd);
    }
};