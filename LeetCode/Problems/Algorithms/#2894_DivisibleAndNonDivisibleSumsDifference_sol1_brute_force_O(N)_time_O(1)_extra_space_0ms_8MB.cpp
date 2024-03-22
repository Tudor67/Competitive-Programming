class Solution {
public:
    int differenceOfSums(int n, int m) {
        int balance = 0;
        for(int num = 1; num <= n; ++num){
            if(num % m == 0){
                balance -= num;
            }else{
                balance += num;
            }
        }
        return balance;
    }
};