class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        
        vector<long long> uglyNumbers = {1};
        while((int)uglyNumbers.size() < n){
            long long nextUglyNumber = min({uglyNumbers[i2] * 2,
                                            uglyNumbers[i3] * 3,
                                            uglyNumbers[i5] * 5});
                                      
            if(nextUglyNumber == uglyNumbers[i2] * 2){
                i2 += 1;
            }
            if(nextUglyNumber == uglyNumbers[i3] * 3){
                i3 += 1;
            }
            if(nextUglyNumber == uglyNumbers[i5] * 5){
                i5 += 1;
            }

            uglyNumbers.push_back(nextUglyNumber);
        }

        return uglyNumbers[n - 1];
    }
};