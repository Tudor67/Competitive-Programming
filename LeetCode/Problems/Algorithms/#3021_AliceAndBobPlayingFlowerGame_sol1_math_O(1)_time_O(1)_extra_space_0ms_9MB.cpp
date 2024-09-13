class Solution {
private:
    long long countEvenNumbers(long long n){
        return (n / 2);
    }
    
    long long countOddNumbers(long long n){
        return (n + 1) / 2;
    }
    
public:
    long long flowerGame(int n, int m) {
        return countEvenNumbers(n) * countOddNumbers(m) +
               countOddNumbers(n) * countEvenNumbers(m);
    }
};