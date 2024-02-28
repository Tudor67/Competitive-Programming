class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;

        for(int i = low; i <= high; ++i){
            if(10 <= i && i <= 99){
                if(i / 10 == i % 10){
                    res += 1;
                }
            }
            
            if(1000 <= i && i <= 9999){
                if(i / 1000 + (i / 100) % 10 == (i / 10) % 10 + i % 10){
                    res += 1;
                }
            }
        }

        return res;
    }
};