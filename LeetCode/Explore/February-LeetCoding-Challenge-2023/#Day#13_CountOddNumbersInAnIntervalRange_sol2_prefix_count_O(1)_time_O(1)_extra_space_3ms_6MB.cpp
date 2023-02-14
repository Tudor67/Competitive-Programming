class Solution {
private:
    int prefixCountOfOddNums(int n){
        return (n + 1) / 2;
    }

public:
    int countOdds(int low, int high) {
        return prefixCountOfOddNums(high) - prefixCountOfOddNums(low - 1);
    }
};