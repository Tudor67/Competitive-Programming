class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int multiples = n / m;
        int multiplesSum = m * multiples * (multiples + 1) / 2;
        int nonMultiplesSum = totalSum - multiplesSum;
        return nonMultiplesSum - multiplesSum;
    }
};