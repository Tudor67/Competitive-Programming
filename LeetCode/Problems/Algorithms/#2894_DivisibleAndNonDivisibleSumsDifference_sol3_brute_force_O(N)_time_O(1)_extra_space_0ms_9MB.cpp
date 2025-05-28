class Solution {
public:
    int differenceOfSums(int n, int m) {
        int diff = 0;
        for(int num = 1; num <= n; ++num){
            if(num % m == 0){
                diff -= num;
            }else{
                diff += num;
            }
        }
        return diff;
    }
};