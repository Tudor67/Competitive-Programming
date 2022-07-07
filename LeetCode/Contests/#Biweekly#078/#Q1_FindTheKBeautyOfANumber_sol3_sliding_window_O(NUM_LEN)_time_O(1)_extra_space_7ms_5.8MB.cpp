class Solution {
public:
    int divisorSubstrings(int num, int k) {
        const int INITIAL_NUM = num;
        
        int count = 0;
        int i = 0;
        int x = 0;
        int currentPow = 1;
        while(num > 0){
            int digit = num % 10;
            if(i >= k){
                x /= 10;
            }
            x += digit * currentPow;
            
            if(i >= k - 1 && x != 0 && INITIAL_NUM % x == 0){
                count += 1;
            }
            
            if(i + 1 <= k - 1){
                currentPow *= 10;
            }
            num /= 10;
            i += 1;
        }
        
        return count;
    }
};