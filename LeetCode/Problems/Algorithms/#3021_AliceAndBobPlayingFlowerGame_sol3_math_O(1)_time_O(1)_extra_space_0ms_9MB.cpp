class Solution {
private:
    long long countEven(long long n){
        return n / 2;
    }

    long long countOdd(long long n){
        return (n + 1) / 2;
    }

public:
    long long flowerGame(int n, int m) {
        return countEven(n) * countOdd(m) +
               countOdd(n) * countEven(m);
    }
};