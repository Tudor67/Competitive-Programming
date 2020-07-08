class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers;
        for(long long two = 1; two <= INT_MAX; two *= 2){
            for(long long three = two; three <= INT_MAX; three *= 3){
                for(long long five = three; five <= INT_MAX; five *= 5){
                    ugly_numbers.push_back(five);
                }
            }
        }
        sort(ugly_numbers.begin(), ugly_numbers.end());
        return ugly_numbers[n - 1];
    }
};