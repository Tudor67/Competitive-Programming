class Solution {
private:
    int sumOfMultiples(int x, int n){
        int xMultiplesCount = n / x;
        return x * xMultiplesCount * (xMultiplesCount + 1) / 2;
    }
    
public:
    int sumOfMultiples(int n) {
        return sumOfMultiples(3, n) + sumOfMultiples(5, n) + sumOfMultiples(7, n)
             - sumOfMultiples(3 * 5, n) - sumOfMultiples(3 * 7, n) - sumOfMultiples(5 * 7, n)
             + sumOfMultiples(3 * 5 * 7, n);
    }
};