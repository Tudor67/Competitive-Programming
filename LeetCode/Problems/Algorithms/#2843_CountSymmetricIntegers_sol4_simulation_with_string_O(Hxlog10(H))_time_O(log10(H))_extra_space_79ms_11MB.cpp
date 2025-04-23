class Solution {
private:
    bool isSymmetric(int num){
        string s = to_string(num);
        int len = s.length();

        if(len % 2 == 1){
            return false;
        }

        int lSum = 0;
        int rSum = 0;
        for(int i = 0; i < len; ++i){
            if(i < len / 2){
                lSum += (s[i] - '0');
            }else{
                rSum += (s[i] - '0');
            }
        }

        return (lSum == rSum);
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