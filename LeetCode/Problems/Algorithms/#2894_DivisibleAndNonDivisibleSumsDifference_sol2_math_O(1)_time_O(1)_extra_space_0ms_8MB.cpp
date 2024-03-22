class Solution {
public:
    int differenceOfSums(int n, int m) {
        int multiples = n / m;
        int multiplesSum = m * multiples * (multiples + 1) / 2;
        int nonMultiplesSum = n * (n + 1) / 2 - multiplesSum;
        return nonMultiplesSum - multiplesSum;
    }
};