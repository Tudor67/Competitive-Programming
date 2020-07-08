class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers = {1};
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for(int i = 2; i <= n; ++i){
            int minimum = min({2LL * ugly_numbers[p2], 3LL * ugly_numbers[p3], 5LL * ugly_numbers[p5]});
            if(minimum == 2LL * ugly_numbers[p2]){ p2 += 1; }
            if(minimum == 3LL * ugly_numbers[p3]){ p3 += 1; }
            if(minimum == 5LL * ugly_numbers[p5]){ p5 += 1; }
            ugly_numbers.push_back(minimum);
        }
        return ugly_numbers[n - 1];
    }
};