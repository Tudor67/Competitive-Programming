class Solution {
private:
    bool isSymmetric(int num){
        if(10 <= num && num <= 99){
            return (num / 10) == (num % 10);
        }else if(1000 <= num && num <= 9999){
            return (num / 1000 + num / 100 % 10) == (num / 10 % 10 + num % 10);
        }
        return false;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int symmetricNums = 0;
        for(int num = low; num <= high; ++num){
            if(isSymmetric(num)){
                symmetricNums += 1;
            }
        }
        return symmetricNums;
    }
};