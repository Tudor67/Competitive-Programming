class Solution {
public:
    char findKthBit(int n, int k) {
        char res = '0';

        while(n > 1){
            int size = (1 << n) - 1;
            int mid = (size + 1) / 2;
            if(k == mid){
                return res ^ 1;
            }else if(k > mid){
                k = size - k + 1;
                res ^= 1;
            }
            n -= 1;
        }

        return res;
    }
};