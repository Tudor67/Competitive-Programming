class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers;

        for(long long p2 = 1; p2 <= INT_MAX; p2 *= 2){
            for(long long p3 = 1; p2 <= INT_MAX / p3; p3 *= 3){
                for(long long p5 = 1; p2 * p3 <= INT_MAX / p5; p5 *= 5){
                    uglyNumbers.push_back(p2 * p3 * p5);
                }
            }
        }

        nth_element(uglyNumbers.begin(), uglyNumbers.begin() + n - 1, uglyNumbers.end());

        return uglyNumbers[n - 1];
    }
};