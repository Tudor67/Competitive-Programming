class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> ugly_numbers;
        
        long long x2 = 1;
        for(int p2 = 0; p2 < 31; ++p2){
            if(p2 > 0){
                x2 *= 2;
            }
            long long x3 = 1;
            for(int p3 = 0; p3 < 20; ++p3){
                if(p3 > 0){
                    x3 *= 3;
                }
                long long x5 = 1;
                for(int p5 = 0; p5 < 14; ++p5){
                    if(p5 > 0){
                        x5 *= 5;
                    }
                    if(x2 * x3 <= INT_MAX / x5){
                        ugly_numbers.insert(int(x2 * x3 * x5));
                    }
                }
            }
        }
        
        while(n > 1){
            ugly_numbers.erase(ugly_numbers.begin());
            n -= 1;
        }
        
        return *ugly_numbers.begin();
    }
};