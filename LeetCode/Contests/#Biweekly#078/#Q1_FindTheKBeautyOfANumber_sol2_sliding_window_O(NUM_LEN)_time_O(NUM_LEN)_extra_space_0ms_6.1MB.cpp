class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numStr = to_string(num);
        const int NUM_LEN = numStr.length();
        
        int count = 0;
        int x = 0;
        int maxPow = pow(10, k - 1);
        for(int i = 0; i < NUM_LEN; ++i){
            if(i >= k){
                x -= maxPow * (numStr[i - k] - '0');
            }
            x = 10 * x + (numStr[i] - '0');
            if(i >= k - 1 && x != 0 && num % x == 0){
                count += 1;
            }
        }
        
        return count;
    }
};