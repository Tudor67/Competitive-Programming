class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        int num = 1;
        while(n >= 1){
            sum += num;
            if(num == k / 2){
                num = k;
            }else{
                num = num + 1;
            }
            n -= 1;
        }
        return sum;
    }
};