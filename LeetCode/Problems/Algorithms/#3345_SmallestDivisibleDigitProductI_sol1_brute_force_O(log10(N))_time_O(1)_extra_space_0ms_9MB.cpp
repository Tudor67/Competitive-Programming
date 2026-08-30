class Solution {
private:
    int digitsProduct(int n){
        int prod = 1;
        while(n > 0){
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }

public:
    int smallestNumber(int n, int t) {
        while(digitsProduct(n) % t != 0){
            ++n;
        }
        return n;
    }
};